## General instructions

The objetive is to create a single-page app.

## Ex00

Create a new app and a entity Post with id, title, content, and "created". Created must be set using doctrine events.

## Ex01

Set up security.

Only logged in users can create posts.

Create a UserController with a loginAction and route /login. It retursn a template login.html.twig with a form. The form should be submitted via ajax.

Create a PostController with a defaultAction for default path, should return a index.html.twig. The template should display the login form if the user is not logged, or a post form with title and content. The post should be submited via Ajax and display a confirmation message if success.

If the login credentials are incorrect, a browser alert should be returned.

## Ex02

Create a list below the form on the main page. The list should display all the posts creates with title and date. Everyone can see the list.

The submitting of the form now should update the list adding the posts to the end.

Implement validation for the form to make sure the title is unique. If there's an error, you should get an alert.

## Ex03

Create an action on PostController called ViewAction with the route /view/{id}. Should be called using ajax when clicking the title and should return the post details. The details should be displayed above the form.

Create a deleteAction with route /delete/{id}. Only logged users can delete a post. 

The post details should have a delete button that shows a confirmation dialog. It should update the post lists too.

## Ex04

Set up a websocket server using symfony on port 8080. Use a custom command "bin/console websocket:server"

On the client, create a websocket using JS. Each time a new post is added or deleted in any browser window, you will have the update the post on all clients.
