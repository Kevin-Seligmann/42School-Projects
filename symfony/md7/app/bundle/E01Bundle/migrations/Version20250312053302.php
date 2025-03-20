<?php

declare(strict_types=1);

namespace E01Migrations;

use Doctrine\DBAL\Schema\Schema;
use Doctrine\Migrations\AbstractMigration;

/**
 * Auto-generated Migration: Please modify to your needs!
 */
final class Version20250312053302 extends AbstractMigration
{
    public function getDescription(): string
    {
        return '';
    }

    public function up(Schema $schema): void
    {
        // this up() migration is auto-generated, please modify it to your needs
        $this->addSql('CREATE TABLE e01_user (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, username VARCHAR(180) NOT NULL, roles CLOB NOT NULL --(DC2Type:json)
        , password VARCHAR(255) NOT NULL)');
        $this->addSql('CREATE UNIQUE INDEX UNIQ_IDENTIFIER_USERNAME ON e01_user (username)');
        $this->addSql('CREATE TABLE e03_post (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, author_id INTEGER NOT NULL, title VARCHAR(50) NOT NULL, content CLOB NOT NULL, created DATETIME NOT NULL, CONSTRAINT FK_16294A6CF675F31B FOREIGN KEY (author_id) REFERENCES e01_user (id) NOT DEFERRABLE INITIALLY IMMEDIATE)');
        $this->addSql('CREATE INDEX IDX_16294A6CF675F31B ON e03_post (author_id)');
        $this->addSql('CREATE TABLE post_edit (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, editor_id INTEGER NOT NULL, post_id INTEGER NOT NULL, date DATETIME NOT NULL, CONSTRAINT FK_4860B9116995AC4C FOREIGN KEY (editor_id) REFERENCES e01_user (id) NOT DEFERRABLE INITIALLY IMMEDIATE, CONSTRAINT FK_4860B9114B89032C FOREIGN KEY (post_id) REFERENCES e03_post (id) NOT DEFERRABLE INITIALLY IMMEDIATE)');
        $this->addSql('CREATE INDEX IDX_4860B9116995AC4C ON post_edit (editor_id)');
        $this->addSql('CREATE UNIQUE INDEX UNIQ_4860B9114B89032C ON post_edit (post_id)');
        $this->addSql('CREATE TABLE vote (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, voter_id INTEGER NOT NULL, post_id INTEGER NOT NULL, type INTEGER DEFAULT NULL, CONSTRAINT FK_5A108564EBB4B8AD FOREIGN KEY (voter_id) REFERENCES e01_user (id) NOT DEFERRABLE INITIALLY IMMEDIATE, CONSTRAINT FK_5A1085644B89032C FOREIGN KEY (post_id) REFERENCES e03_post (id) NOT DEFERRABLE INITIALLY IMMEDIATE)');
        $this->addSql('CREATE INDEX IDX_5A108564EBB4B8AD ON vote (voter_id)');
        $this->addSql('CREATE INDEX IDX_5A1085644B89032C ON vote (post_id)');
    }

    public function down(Schema $schema): void
    {
        // this down() migration is auto-generated, please modify it to your needs
        $this->addSql('DROP TABLE e01_user');
        $this->addSql('DROP TABLE e03_post');
        $this->addSql('DROP TABLE post_edit');
        $this->addSql('DROP TABLE vote');
    }
}
