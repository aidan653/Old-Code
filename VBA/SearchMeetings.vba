Sub Main()
Dim objNameSpace As Outlook.NameSpace
Dim objTempFolder As Outlook.MAPIFolder
Dim startTime As Date
Dim endTime As Date

Set objNameSpace = Application.GetNamespace("MAPI")
Set objMainFolder = objNameSpace.GetFolderFromID("00000000607A3D4BFF527046936DC23528AED3D401007E4952D61314EA43A3CC2117610B3FE700000000010D0000")
startTime = DateSerial(2023, 7, 18)
endTime = DateSerial(2023, 8, 1)
Call SearchMeetings(objMainFolder, startTime, endTime)
End Sub

Sub SearchMeetings(ByVal folder As Outlook.folder, ByVal startTime As Date, ByVal endTime As Date)
Dim filter As String
Dim calItems As Outlook.Items
Dim restrictItems As Outlook.Items
Dim appt As Outlook.AppointmentItem
filter = "[Start] >= '" & _
    Format$(startTime, "mm/dd/yyyy hh:mm AMPM") _
    & "' AND [End] <= '" & _
    Format$(endTime, "mm/dd/yyyy hh:mm AMPM") & "'"
Set calItems = folder.Items

calItems.IncludeRecurrences = True
calItems.Sort ("[Start]")
Set restrictItems = calItems.Restrict(filter)
For Each appt In restrictItems
    Debug.Print appt.start & "     " & appt.Subject
Next
End Sub
