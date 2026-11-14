def Job_Scheduling(Jobs,Profits,Deadlines):
    n=len(Deadlines)
    Schedule=[(Jobs[i],Profits[i],Deadlines[i]) for i in range(n)]

    Schedule.sort(reverse=True)
    max_deadline=max(Deadlines)
    sol=[None]*(max_deadline+1)

    tot_prp=0.0
    no_jobs=0

    for job,profit,deadline in Schedule:
        for slot in range(deadline,0,-1):
            if sol[slot] is None:
                sol[slot]=job
                no_jobs+=1
                tot_prp=tot_prp+profit;
                break
        if job==deadline:
            break

    final_schedule=[i for i in sol[1:] if i is not None]
    return tot_prp,final_schedule,no_jobs;

n=int(input("Enter the size of the array:"))
jobs=[]
profits=[]
deadlines=[]

for i in range(n):
    ele=input(f"Job[{i+1}]:")
    jobs.append(ele)
    pro=float(input(f"Profit[{i+1}]:"))
    profits.append(pro)
    dead=int(input(f"Deadline[{i+1}]:"))
    deadlines.append(dead)


profit,job,tot_jobs=Job_Scheduling(jobs,profits,deadlines)
print("Total Profit:",profit)
print("By Jobs:",job)
print("No. of Jobs done:",tot_jobs)
