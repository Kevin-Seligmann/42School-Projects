## Ex00

Set up a default Symfony application

## Ex01

Create a configuration file with a root key "d07" and include the following subkeys: "number" (Integer, mandatory), and "enable" (Optiona, boolean, default true)

Add the keys to config/packages/app.yml

Create a controller Ex01Controller with an action ex01Action and route ex01. Should return a text with the number from the configuration.

## Ex02

Set the defaut locale for the app (English or French) and enable translations.

Create the files messages.en.yml and messages.fr.yml

Create a controller Ex02Controller, actions "translations-Action" which should take a parameter "count (Def 0, between 0 and 9)" and route /{_locale}/ex02/{count}.

Depending on _locale, the site should be on English or French.

Create a template ex02.html.twig displayed by the action. It should have the number of the configuration and the count number.

The template should contain text and should be retrieved from the files using the keys ex02.number and ex02.count

### English

• The config number is %number% - the correct parameter should be passed to this
translation

• none|one|number %count% - depending on the parameter value, a different translation should be used

### French

Le numéro de configuration est %number% - the correct parameter should be passed
to this translation

aucun|un|nombre %count% - depending on the parameter value, a different translation should be used

## Ex03

Create a twig extension 

Create a twig filter and a twig function. The filter should be called uppercaseWords and should uppercase the first letter of each word on a string.

The function countNumbers will return the number of digits of a string.

These should be created on a service src/Service/Ex03Service injected on the extension.

Create a Ex03Controller with an action extension-Action, route /ex03 and template ex03.html.twig. Test the filter and the function.

## Ex04

Using PHPUnit. Create a test class for the service which should follow Symfony test naming conventions. test the two functions. Write at least 3 assets for each function.
