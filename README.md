# Prologue

I'm trying to build a shopping website with the knowdege I've learned so far (Aug 18, 2020).<br>
I want the website to have all the features that the prevailing shopping websites have.<br>
This is a big project and it's full-stack. I'm planning to spend a week to implement it.<br>
I purposefully plan as many features as possible, but it doesn't have to do all the planned <br>
features. It at least should be a working website.<br>

Albert<br>
Aug 18, 2020

# Plan

- **Features**

  - **Identity Verification**
      - A home page that allows user either log-in or register.
      - New users should register in the same page instead of open another page.
      - Registered user should enter correct username and password to log in.

  - **Shopping**
      - After logging in, buyers could shop in-stock products.
      - Buyers have $100 initial balance. They can top-up their balance.
      - Buyers can click on the product link to the product page.
      - The product page should include product's information and a purchase button.
      - If user's balance is insufficient, direct them to the top-up page.

  - **Selling**
    - After logging in, sellers could stock their products.
    - Sellers chould set up the name, price, and quantity of their products.

- **Technology Selection**

  - Available technologies
    - Back-end: C++
    - Front-end: HTML, CSS, JavaScript, maybe Vue.js for the dynamic animation
    - Interface: CGI (Common Gateway Interface)

  - Currently not planning to handle a large database since I have no knowledge on database
    technologies such as MySQL.
  
  - I will use C++ to parse, read, and write data.

  - Identity verification should be simple.
    - Log-in process should not limit the number of try time.
    - Register process should not require users to use complex password.

## Version 1.0 (Aug 18, 2020)
### Project Structure

- index.htm
  - The homepage that contains a form element with action link to CGI file and "GET" method:
    - Two input fields to let the user enters their username and password
    - Two radio buttons to choose between buyer and seller
    - A link to register.htm

- main.cpp
  - Receive the URL from index.htm
  - Parse the URL and extract the user type from query string
  - Open the corresponding html page
  - Compile to CGI (Common Gateway Interface) file and save as "cgi-bin/main.cgi"

- register.htm
  - A form for user to input their 
    - Username
    - Password
    - Confirm password

- buyer.htm
  - Display all the availble items in stock using list
  - When user click on the item it will link to a new page with item information
  - The new page has a purchase button to let the user purchase it
  - If the user's balance is less thant the item's price, prompt and direct the user to the top-up page

- seller.htm
  - Sellers can manage their items
  - They can see status of their in-stock items
  - They can stock new items

### Class
- Product
  - Product name
  - Price
  - Quantity
- User (Base Class)
  - Username
  - Password
- Buyer : User
  - Balance

# Development Log

- 8/20/2020
  - Added classes Product, User, and Buyer
  - Added index.htm, style.css

- 8/22/2020
  - Moved whole project to Visual Studio Code. Coping with Visual Studio 2019 is really annoying and time-wasting. Currently my project doesn't need any of the features of Visual Studio. So now I'm using VS Code which is much better.
  - Finished the scratch version of the login page. Next is to implement the C++ back-end.

- 8/23/2020
  - Understood how Visual Studio 2019 manages solution and projects.
  - Fixed problem <bold>"can't push to GitHub because don't have permisson to *.vs.opendb file"</bold>, solution: ignore it in .gitignore.
  - Succesfully configured main.cpp to output CGI file in cgi-bin. Still need to figure out how CGI works.