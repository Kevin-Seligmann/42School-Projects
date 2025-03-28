<?php

return [
    Symfony\Bundle\FrameworkBundle\FrameworkBundle::class => ['all' => true],
    Symfony\Bundle\SecurityBundle\SecurityBundle::class => ['all' => true],
    Symfony\Bundle\TwigBundle\TwigBundle::class => ['all' => true],
    Symfony\Bundle\MakerBundle\MakerBundle::class => ['dev' => true],
    Doctrine\Bundle\DoctrineBundle\DoctrineBundle::class => ['all' => true],
    Doctrine\Bundle\MigrationsBundle\DoctrineMigrationsBundle::class => ['all' => true],
    Symfony\Bundle\MonologBundle\MonologBundle::class => ['all' => true],
    App\Bundle\E01Bundle\E01Bundle::class => ['all' => true],
    App\Bundle\E02Bundle\E02Bundle::class => ['all' => true],
    App\Bundle\E03Bundle\E03Bundle::class => ['all' => true],
    App\Bundle\E04Bundle\E04Bundle::class => ['all' => true],
    App\Bundle\E05Bundle\E05Bundle::class => ['all' => true],
    App\Bundle\E06Bundle\E06Bundle::class => ['all' => true],
    App\Bundle\E07Bundle\E07Bundle::class => ['all' => true],
    Symfony\UX\TwigComponent\TwigComponentBundle::class => ['all' => true],
    Doctrine\Bundle\FixturesBundle\DoctrineFixturesBundle::class => ['dev' => true, 'test' => true],
];
