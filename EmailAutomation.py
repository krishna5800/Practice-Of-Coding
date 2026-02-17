# ///////////////////////////////////////////////////////////
# //
# //    Program : Simple Gamil Mail Sender
# //    Author  : Krishna Govindrav Hitnalikar
# //    Purpose : Send mail using Python SMTP
# //
# ///////////////////////////////////////////////////////////

# ///////////////////////////////////////////////////////////
# //
# //    Include necessary libraries
# //
# ///////////////////////////////////////////////////////////

import smtplib
from email.message import EmailMessage

# ///////////////////////////////////////////////////////////
# //
# //    Function    : Mail_Send
# //    Author      : Krishna Govindrav Hitnalikar
# //    Purpose     : Sends email using Gmail SMTP server
# //
# ///////////////////////////////////////////////////////////

def Mail_Send(sender, app_password, receiver, subject, body):

    # Step 1 : Create Email object
    msg = EmailMessage()

    # Step 2 : Set mail header
    msg["From"] = sender
    msg["To"] = receiver
    msg["Subject"] = subject

    # Step 3 : Add mail body
    msg.set_content(body)

    # Step 4 : Create SMTP SSL connection manually
    smtp = smtplib.SMTP_SSL("smtp.gmail.com", 465)

    # Step 5 : Login using Gmail + App password
    smtp.login(sender, app_password)

    # Step 6 : Send the email
    smtp.send_message(msg)

    # Step 7 : Close the connection
    smtp.quit()

# ///////////////////////////////////////////////////////////
# //
# //    Function    : main
# //    Author      : Krishna Govindrav Hitnalikar
# //    Purpose     : Driver Code
# //
# ///////////////////////////////////////////////////////////

def main():
    
    # Always use separate temporary/testing account
    sender_email = "testmailforautomation555@gmail.com"

    # App password generated from Google account
    app_password = "your_password_generated_by_gmail"

    # Your second email for testing
    receiver_email = "krishnahitnalikar7@gmail.com"

    # subject for mail
    subject = "Test Mail From Python Script"

    # body of your mail
    body = """ Jay Ganesh...

    This is test email send using Python Script.

    Regards,
    Krishna Govindrav Hitnalikar
    """

    # function call
    Mail_Send(sender_email, app_password, receiver_email, subject, body)

    print("Mail Sent Successfully")

# ///////////////////////////////////////////////////////////
# //
# //    Program Entry Point
# //
# ///////////////////////////////////////////////////////////

if __name__ == "__main__":

    main()