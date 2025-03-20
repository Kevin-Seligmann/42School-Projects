<?php

namespace App\Bundle\E06Bundle\Repository;

use App\Bundle\E03Bundle\Entity\E03Post;
use App\Bundle\E06Bundle\Entity\PostEdit;
use Doctrine\Bundle\DoctrineBundle\Repository\ServiceEntityRepository;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @extends ServiceEntityRepository<PostEdit>
 */
class PostEditRepository extends ServiceEntityRepository
{
    public function __construct(ManagerRegistry $registry)
    {
        parent::__construct($registry, PostEdit::class);
    }

    public function getPostEdit(E03Post $post): ?PostEdit {
        $postEdit = $this->createQueryBuilder('v')
        ->where('v.post = :post')
        ->setParameter('post', $post)
        ->getQuery()
        ->getOneOrNullResult();
    ;
        return $postEdit;
    }  

    //    /**
    //     * @return PostEdit[] Returns an array of PostEdit objects
    //     */
    //    public function findByExampleField($value): array
    //    {
    //        return $this->createQueryBuilder('p')
    //            ->andWhere('p.exampleField = :val')
    //            ->setParameter('val', $value)
    //            ->orderBy('p.id', 'ASC')
    //            ->setMaxResults(10)
    //            ->getQuery()
    //            ->getResult()
    //        ;
    //    }

    //    public function findOneBySomeField($value): ?PostEdit
    //    {
    //        return $this->createQueryBuilder('p')
    //            ->andWhere('p.exampleField = :val')
    //            ->setParameter('val', $value)
    //            ->getQuery()
    //            ->getOneOrNullResult()
    //        ;
    //    }
}
