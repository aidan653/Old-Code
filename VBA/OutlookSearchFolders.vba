Private Sub Main()
    Dim objNameSpace As Outlook.NameSpace
    Dim objMainFolder As Outlook.Folders
    Dim objTempFolder As Outlook.MAPIFolder
    
    Set objNameSpace = Application.GetNamespace("MAPI")
    Set objMainFolder = objNameSpace.Folders
    For Each objTempFolder In objMainFolder
        If (objTempFolder.Name = "RA-PDDist4IT@pa.gov") Then
            Exit For
        End If
    Next
    Call ProcessCurrentFolder(objTempFolder)
End Sub
 
Private Sub ProcessCurrentFolder(ByVal objParentFolder As Outlook.MAPIFolder)
    Dim objCurFolder As Outlook.MAPIFolder
    Dim objMail As Outlook.MailItem
    
    On Error Resume Next
    
    '    Process each items in the folder
    For Each objMail In objParentFolder.Items
        '    Do your task here ...
    Next
    
    '    Process the subfolders in the folder recursively
    If (objParentFolder.Folders.Count > 0) Then
        For Each objCurFolder In objParentFolder.Folders
            Debug.Print "Folder: " + objCurFolder.Name
            Debug.Print "ID: " + objCurFolder.EntryID
            Call ProcessCurrentFolder(objCurFolder)
        Next
    End If
End Sub