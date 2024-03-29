USE [DigitalSignageTest]
GO
/****** Object:  StoredProcedure [dbo].[JoinMeetings]    Script Date: 4/6/2023 8:32:09 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date,,>
-- Description:	<Description,,>
-- =============================================
ALTER PROCEDURE [dbo].[JoinMeetings] @arg int 
	-- Add the parameters for the stored procedure here 
AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;
    -- Daily
    IF @arg = 0
	BEGIN
        SELECT TOP 1000 [Room] ,concat([LastName],', ',[FirstName]) AS Organizer,[Subject],DATEADD(day, DATEDIFF(day,'19000101',[Date]), CAST([Start] AS DATETIME2(7))) AS Start,DATEADD(day, DATEDIFF(day,'19000101',[Date]), CAST([End] AS DATETIME2(7))) AS [End] INTO #DailyMeetingTemp FROM [dbo].[FormScheduledMeetings]
		SELECT coalesce(#DailyMeetingTemp.[Room], DailyMeetings.[Room]) AS Room,coalesce(#DailyMeetingTemp.[Organizer], DailyMeetings.[Organizer]) AS Organizer,coalesce(#DailyMeetingTemp.[Subject], DailyMeetings.[Subject]) AS [Subject],coalesce(#DailyMeetingTemp.[Start], DailyMeetings.[Start]) AS Start,coalesce(#DailyMeetingTemp.[End], DailyMeetings.[End]) AS [End] FROM [dbo].#DailyMeetingTemp
		RIGHT JOIN DailyMeetings on #DailyMeetingTemp.Start = DailyMeetings.Start AND #DailyMeetingTemp.Room = DailyMeetings.Room
		DROP TABLE #DailyMeetingTemp
    END
	-- Weekly
    ELSE IF @arg = 1
    BEGIN
		SELECT TOP 1000 [Room] ,concat([LastName],', ',[FirstName]) AS Organizer,[Subject],DATEADD(day, DATEDIFF(day,'19000101',[Date]), CAST([Start] AS DATETIME2(7))) AS Start,DATEADD(day, DATEDIFF(day,'19000101',[Date]), CAST([End] AS DATETIME2(7))) AS [End] INTO #WeeklyMeetingTemp FROM [dbo].[FormScheduledMeetings]
		SELECT coalesce(#WeeklyMeetingTemp.[Room], WeeklyMeetings.[Room]) AS Room,coalesce(#WeeklyMeetingTemp.[Organizer], WeeklyMeetings.[Organizer]) AS Organizer,coalesce(#WeeklyMeetingTemp.[Subject], WeeklyMeetings.[Subject]) AS [Subject],coalesce(#WeeklyMeetingTemp.[Start], WeeklyMeetings.[Start]) AS Start,coalesce(#WeeklyMeetingTemp.[End], WeeklyMeetings.[End]) AS [End] FROM [dbo].#WeeklyMeetingTemp
		RIGHT JOIN WeeklyMeetings on #WeeklyMeetingTemp.Start = WeeklyMeetings.Start AND #WeeklyMeetingTemp.Room = WeeklyMeetings.Room
		DROP TABLE #WeeklyMeetingTemp
    END
	-- All
	ELSE
	BEGIN
		SELECT TOP 1000 [Room] ,concat([LastName],', ',[FirstName]) AS Organizer,[Subject],DATEADD(day, DATEDIFF(day,'19000101',[Date]), CAST([Start] AS DATETIME2(7))) AS Start,DATEADD(day, DATEDIFF(day,'19000101',[Date]), CAST([End] AS DATETIME2(7))) AS [End] FROM [dbo].[FormScheduledMeetings]
	END
END