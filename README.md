# ⚠️ Note: 
Project is in development. Full output files not yet implemented.

## AdressBuilderSCADA
Small utility to generate SCADA CSV and CODESYS ST code from a user-defined variable list.

## Purpose
Takes a CSV with variables (Name, Data Type, Description) and produces:
A Modbus register map for Simplight SCADA
Assignment code (RegHoldingBuf[N] := var;) for AGAVA PLC (CODESYS 3.5.14 P3-P4)

## How to use
1) Prepare input CSV with columns: Name,Data Type,Description
Example: Motor_Start,BOOL,Start command for main drive motor
2) Run the executable (AdressBuilderSCADA.exe)
3) Output is printed to console.
(SCADA CSV export — coming soon)
(ST code block — coming soon)
