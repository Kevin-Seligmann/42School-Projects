## General instructions

- Every controller has to go under a Controller folder,  should be suffixed with Controller and should have a class with the file name.
- The content of every page should be in twig files and every twig file should have the file extension .html.twig
- The server used is the one integrated in Symfony.
- Only explicit request URLs should render a page without error. The not configured URLs should generate a 404 error.
- The requested URLs should work with and without trailing slash. E.g: both /ex00 and /ex00/ must work

(symfony server:start, opens in 8000)

## ex 00

Install symfony with: composer create-project symfony/skeleton d04 "^versionLTS"

Create a page that is viewable on the following URL /e00/firstpage

Only a controller and no template should be used.

## ex 01

/e01 should give a page with a header, footer, and base page

/e01/\[article\] should display the header, footer, and the article. Provide two.

/e01/wrongurl should display the main page with a list of links to articles

You can define the list of categories in an array inside the controller or you can use set parameters inside the /config/services.yml file of the Bundle

Create a base.html.twig file with <html> and <body>. Other templates should extend this and overwrite the block `content`.

## ex02

The url /e02 must have a form with two inputs. A text field 'message' and a dropdown 'Include timestamp' with two values: Yes, No.

Write to a file: If yes, write message and timestamp on a line. If no, write the message.

Add server-side validation to the message field to not be blank.

The name of the file should be configurable from /config/services.yaml. It should be created in the project root folder.

When the form is submitted. The page should refresh and the from should remember the submitted information. The last line added should be displayed.

Use the Form component from symfony.

## ex03

Create a page that display a number of shades of black, red, blue, and green.

Must be displayed on a table with a header

Table cells must be 40 height and 80 width pixels. The brackground is the shade.

The number of shades is a parameter e03.number_of_colors on services.yaml

Create the shades dinamycally and add then to a twig template.


