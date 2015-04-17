# Homework 1
# family.pl

def parent(p1, p2):
	strlen=len(parents)
	pcount=0
	tp1=''
	tp2=''
	print("| ?- parent(" + p1  + ", " + p2  + ")")
	for i in range(0,strlen):
		if (parents[i][0] == p1) or ((len(p1)==1) and ('A' <= p1[0] <= 'Z')):
			if (parents[i][1] == p2) or ((len(p2)==1) and ('A' <= p2[0] <= 'Z')):
				if(p1 == p2) and (parents[i][0] != parents[i][1]):
					continue
				if pcount==0:
					tp1=parents[i][0]
					tp2=parents[i][1]
					pct=0
					if (len(p1)==1) and ('A' < p1[0] < 'Z'):
						print p1 + ": " + parents[i][0]
						pct=pct+1
					if (len(p2)==1) and ('A' < p2[0] < 'Z'):
						print p2 + ": " + parents[i][1]	
						pct=pct+1
					if(pct!=0):
						print ""
				if pcount==1:
					p1c=0
					if (len(p1)==1) and ('A' < p1[0] < 'Z'):
						p1c=p1c+1
					else:
						print "X: " + tp1
					if (len(p2)==1) and ('A' < p2[0] < 'Z'):
						p1c=p1c+1
					else:
						print "Y: " + tp2
					if(p1c!=2):
						print ""
				if pcount!=0:
					print "X: " + parents[i][0]
					print "Y: " + parents[i][1]
					print ""
				pcount=pcount+1;
	if pcount == 0:
		print ""
		print "no"
	else:
		print ""
		print "yes"

def ancestor(p1, p2):
	strlen=len(ancestors)
	pcount=0
	print("| ?- ancestor(" + p1  + ", " + p2  + ")")
	for i in range(0,strlen):
		if (ancestors[i][0] == p1) or ((len(p1)==1) and ('A' <= p1[0] <= 'Z')):
			if (ancestors[i][1] == p2) or ((len(p2)==1) and ('A' <= p2[0] <= 'Z')):
				if(p1 == p2) and (ancestors[i][0] != ancestors[i][1]):
					continue
				if pcount==0:
					tp1=ancestors[i][0]
					tp2=ancestors[i][1]
					pct=0
					if (len(p1)==1) and ('A' < p1[0] < 'Z'):
						print p1 + ": " + ancestors[i][0]
						pct=pct+1
					if (len(p2)==1) and ('A' < p2[0] < 'Z'):
						print p2 + ": " + ancestors[i][1]	
						pct=pct+1
					if(pct!=0):
						print ""
				if pcount==1:
					p1c=0
					if (len(p1)==1) and ('A' < p1[0] < 'Z'):
						p1c=p1c+1
					else:
						print "X: " + tp1
					if (len(p2)==1) and ('A' < p2[0] < 'Z'):
						p1c=p1c+1
					else:
						print "Y: " + tp2
					if(p1c!=2):
						print ""
				if pcount!=0:
					print "X: " + ancestors[i][0]
					print "Y: " + ancestors[i][1]
					print ""
				pcount=pcount+1;
	if pcount == 0:
		print ""
		print "no"
	else:
		print ""
		print "yes"

parents=[["bob","mary"],["jane","mary"],["mary","peter"],["paul","peter"],["peter","john"]]
ancestors=[["bob","mary"],["jane","mary"],["mary","peter"],["paul","peter"],["peter","john"],["paul","john"],["mary","john"],["jane","john"],["bob","john"],["bob","peter"],["jane","peter"]]

print "| ?- consult(family)."
print ""
print "queries:"
print "=" * 20
parent('bob','mary')
print "=" * 20
parent('bob','X')
print "=" * 20
parent('X', 'Y')
print "=" * 20
ancestor('X', 'Y')