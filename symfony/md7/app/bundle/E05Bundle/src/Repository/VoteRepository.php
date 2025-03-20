<?php

namespace App\Bundle\E05Bundle\Repository;

use App\Bundle\E01Bundle\Entity\E01User;
use App\Bundle\E03Bundle\Entity\E03Post;
use App\Bundle\E05Bundle\Entity\Vote;
use Doctrine\Bundle\DoctrineBundle\Repository\ServiceEntityRepository;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @extends ServiceEntityRepository<Vote>
 */
class VoteRepository extends ServiceEntityRepository
{
    public function __construct(ManagerRegistry $registry)
    {
        parent::__construct($registry, Vote::class);
    }

    public function findVote(E01User $user, E03Post $post): ?Vote
    {
        return $this->createQueryBuilder('v')
            ->where('v.voter = :voter')
            ->andWhere('v.post = :post')
            ->setParameter('voter', $user)
            ->setParameter('post', $post)
            ->getQuery()
            ->getOneOrNullResult()
        ;
    }

    public function getUserReputation(E01User $user): void
    {
        $reputation = $this->createQueryBuilder('v')
            ->select('SUM(v.type)')
            ->join('v.post', 'p')
            ->where('p.author = :author')
            ->setParameter('author', $user)
            ->getQuery()
            ->getSingleScalarResult()
        ;
        if ($reputation)
            $user->setReputation($reputation);
        else
            $user->setReputation(0);
    }

    public function getPostLikes(E03Post $post): void
    {
        $likes = $this->createQueryBuilder('v')
            ->select('COUNT(v.id)')
            ->where('v.post = :post')
            ->andWhere('v.type = 1')
            ->setParameter('post', $post)
            ->getQuery()
            ->getSingleScalarResult()
        ;
        $post->setLikes($likes);
    }

    public function getPostDislikes(E03Post $post): void
    {
        $dislikes = $this->createQueryBuilder('v')
            ->select('COUNT(v.id)')
            ->where('v.post = :post')
            ->andWhere('v.type = -1')
            ->setParameter('post', $post)
            ->getQuery()
            ->getSingleScalarResult()
        ;
        $post->setDislikes($dislikes);
    }


//    /**
//     * @return Vote[] Returns an array of Vote objects
//     */
//    public function findByExampleField($value): array
//    {
//        return $this->createQueryBuilder('v')
//            ->andWhere('v.exampleField = :val')
//            ->setParameter('val', $value)
//            ->orderBy('v.id', 'ASC')
//            ->setMaxResults(10)
//            ->getQuery()
//            ->getResult()
//        ;
//    }

//    public function findOneBySomeField($value): ?Vote
//    {
//        return $this->createQueryBuilder('v')
//            ->andWhere('v.exampleField = :val')
//            ->setParameter('val', $value)
//            ->getQuery()
//            ->getOneOrNullResult()
//        ;
//    }
}
