<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="hw5.Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Student Information</title>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
    <script type="text/javascript">
        function login() {
            var username = $('#<%= username.ClientID %>').val();
            var password = $('#<%= password.ClientID %>').val();

            if (username === "user" && password === "pass") {
                fetchStudents();
            } else {
                alert("Invalid credentials");
            }
        }

        function fetchStudents() {
            $.ajax({
                type: "POST",
                url: "Default.aspx/GetStudents",
                contentType: "application/json; charset=utf-8",
                dataType: "json",
                success: function (response) {
                    displayStudentInfo(response.d);
                },
                error: function (error) {
                    alert("Error fetching student data");
                }
            });
        }

        function displayStudentInfo(students) {
            var studentInfo = "<h2>Student Information</h2>";
            studentInfo += "<ul>";
            $.each(students, function (index, student) {
                studentInfo += "<li>" + student.FirstName + " " + student.LastName + " (Age: " + student.Age + ")</li>";
            });
            studentInfo += "</ul>";
            $('#student-info').html(studentInfo);
        }
    </script>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h1>Login</h1>
            <div>
                <label for="username">Username:</label>
                <asp:TextBox ID="username" runat="server"></asp:TextBox>
                <label for="password">Password:</label>
                <asp:TextBox ID="password" runat="server" TextMode="Password"></asp:TextBox>
                <asp:Button ID="loginButton" runat="server" Text="Login" OnClientClick="login(); return false;" />
            </div>
        </div>
        <div id="student-info"></div>
    </form>
</body>
</html>
<script type="text/javascript">
    function changeLanguage(lang) {
        if (lang === 'en') {
            // Set English text
            document.getElementById('<%= username.ClientID %>').placeholder = 'Username';
            document.getElementById('<%= password.ClientID %>').placeholder = 'Password';
            document.getElementById('<%= loginButton.ClientID %>').value = 'Login';
            // Add more localization as needed
        } else if (lang === 'tr') {
            // Set Turkish text
            document.getElementById('<%= username.ClientID %>').placeholder = 'Kullanıcı Adı';
            document.getElementById('<%= password.ClientID %>').placeholder = 'Şifre';
            document.getElementById('<%= loginButton.ClientID %>').value = 'Giriş';
            // Add more localization as needed
        }
    }
</script>

