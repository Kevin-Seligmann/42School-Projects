## Database / SQL Module

- Use both annotations and configuration files for defining routes
- Use controller-defined forms
- Each page must be properly formatted and contain DocType, HTML, BODY, HEAD
- Symfony default server
- Each exercise should have its own table in the DB
- Table for mode 'Person' = 'persons' (Example)

## ex00

Configure DB connection
Write a SQL query that will create a table
Create a route to call that SQL
No ORM this exercise
Create a page that contains a button/link to create the database and a success/error message.

Table:
- id - integer - PK
- username - string - unique
- name - string
- email - string - unique
- enable - boolean
- birthdate - datetime
- address - long text

Should not fail if the table exists

## ex01

Create the same table using ORM.

## ex02

Use only SQL

Create a new table for this execirse

Crea a form and a `show form` action in the controller

Create endpoints in the controller for Show form, handle insertion and view data. And a table webpage with the data.

Should not fail if the data already is present

## ex03

Use Doctrine ORM

Create a new entity with a table

Create a form and map it to the entity

Create endpoints in the controller for Show form, handle insertion and view data. And a table webpage with the data.

The form should contain validation

The ORM commands should not be handled in the controller

## Ex04

Add a delete option with SQL

## Ex05

Add a delete option with ORM

## Ex06

Add a update button for each entity. This button redirects to a edit page.

An autocompleted form should be shown.

Use only SQL

Display a success message on the list page

## Ex07

Add a update button for each entity. This button redirects to a edit page.

An autocompleted form should be shown.

Use only ORM

Display a success message on the list page

## Ex08 (Incomplete)

(I started this exercise without knowing SQLIte doesn't support adding FK to an existing table. But the query is writen anyways)

Using SQL.

Create the table from the exercise 00 without the address field.

Create a controller method which will add a new column to this table.

Create a controller method for creating a table bank_accounts and a table addresses.

Create a one-to-one relationship between bank_account and person. 

Create a one-to-many relationship between addresses and person.

For each operation return a message.

# Ex09 (Not done)

(I dont think Doctrine is made to use in controllers like this. So I skip this for now.
 I know it's possible to create custom commands. But it doesn't seem to be what it's intended here.
 The issue is altering an entity to add a new field.)

Create a person entity.

Add a new field like the previous exercise on the entity, and update the database.

Create two new entities BankAccount and Address, and perform the relations.

Use a controller to update the database.

# Ex10

Using both ORM and SQL...

Create a table both with SQL and with an entity.

Write a controller that will read a file and inser the data in both.

It should be possible to call the controller from a link and see the data on a table.

# Ex11

Use the tables from exercise 9 or similar

Design a webpage with a table in which present the stored information.

Add a form with filtering and sorting

Create methods in the controller for handling the listing properly

Make sure the information in the table comes from more than one table (JOIN)

Use SQL only

Add validation for the request

# Ex12

Repeat the previous exercise with ORM.

Create special repository queries to feching the information

# Ex13

Use only ORM

Create a employee with id, firstname, lastname, email, birthdate, active (bool), employed_since, employed_until, hours (ENUM, 8, 6, 4), salary, position (ENUM, manager, account_manager, qa_manager, dev_manager, ceo, coo, backend_dev, frontend_dev, qa_tester)

Create a one-to-many between Employee and itself. Each employee should have a manager.

Implement a read, edit, delete and create endpoin.

### Not done
Create form validation for editing/creating. (required, unique, email with format, etc)

Success/error messages

The aplication should not crash

# Ex14

Create a controller that will insert a table to the database.

The table status should be represented in a webpage "Exists" "Doesn't exists"

Create a form mapped to a controller action to insert information.

Add a function SQL injection using JS on the form submit event

The result should be visible in the homepage

