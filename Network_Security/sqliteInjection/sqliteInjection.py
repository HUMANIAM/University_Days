import sqlite3 as sqlite
import sys

db ='sqliteInjection.db'
conn = sqlite.connect(db)
cursor = conn.cursor()


def main():
	try:
		if(len(sys.argv) != 2):
			print("Please, Enter command in this format: python scriptname options[-t/-f]")
		else:
			passw = input("Enter your password : ")
			if sys.argv[1] == "-f":
				cursor.execute("SELECT * FROM passwords WHERE password = ?", (passw,))
			else:
				command = "SELECT * FROM passwords WHERE password = %s" % (passw)
				cursor.executescript(command)

			found = cursor.fetchone()
			if found is not None:
			    print('welcome ', found[0])
			else:
				print('sorry you are not in db')
		
	except Exception as e:
		print("execption: ", e)
	finally:
		conn.close()

if __name__ == '__main__':
	main()