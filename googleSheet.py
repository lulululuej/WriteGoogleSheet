import pygsheets

sheetUrl = 'https://docs.google.com/spreadsheets/d/your_url/edit?usp=sharing'

def writeInGoogleSheet(row, x):
  gc = pygsheets.authorize(service_file='/Users/ejchow/2.NTUST/Thesis/QoS_Simulation/googleSheet.json')
  sht = gc.open_by_url(sheetUrl)
  wks = sht[0] # which page you wanna write in GoogleSheet, 0 is the first page.
  wks.update_values_batch([f'A{row}'], [[[x]]])  # check https://pygsheets.readthedocs.io/en/stable/worksheet.html to get more detail info