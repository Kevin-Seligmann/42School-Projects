## General instructions

Each exercise should be have its Bundle named ExxBundle and base route /eXX

## Ex01

Set un a default application

Set up the Symfony security and add a login and register form. Users should be loaded from a database.

Add a homepage with a welcome message

Put the name of the logged user and a logout button, or a link to the register/login form.

## Ex02

Create an Administrator role for the users.

Administratos have access to a page where all users are shown.

Administrator can delete an user but itself.

## Ex03

Create a Post entity with fields title, content, created (date) and author (User).

Homepage should display a list with all the posts ordered from newest to oldest. With title, name of author, creation date.

Each title should have a link to view the post. Accesible by logged in users.

The homepage should have a link for users to create a post.

## Ex04

Users not logged in should have a session that lasts one minute. It will have a random name "Anonymous + animal".

The name will be displayed in the homepage.

A message will be displayed showing the time in seconds since the last request

## Ex05

Logged in users can upvote and downvote a post. On the post detail page. A user can vote only once.

The post list on the homepage should display the amount of likes/dislikes.

When a username apperas on the website, a reputation socre should be shown. It's the sum of receives likes/dislikes.

## Ex06

Logged in users should be able to edit a post. 

At the bottom of a post, a text should appear saying which user last edited the post and at what date/time.

## Ex07

Depending on the reputation.

- 0 - Create and edit their own post
- 3 - Like posts
- 6 - Dislike posts
- 9+ - Edit any posts

Admin can do anything

Use Doctrine Fixtures to populate the database with test users, posts and votes.
