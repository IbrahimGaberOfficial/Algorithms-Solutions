using System;

namespace EmployeeImportance{
	 public class Program
    {
        static public void Main()
        {
            Solution sol = new Solution();
            List<Employee> employees = new List<Employee>();
            // Create some employees
            Employee employee1 = new Employee(1, 5); // ->2    -> 5
            Employee employee2 = new Employee(2, 3); // ->3    -> 7
            Employee employee3 = new Employee(3, 2);
            Employee employee5 = new Employee(5, 1);
            Employee employee7 = new Employee(7, -1);

            // Add subordinates to Emp1
            employee1.AddSubordinate(2);
            employee1.AddSubordinate(5);
            // Add subordinates to Emp2
            employee2.AddSubordinate(3);
            employee2.AddSubordinate(7);


            // Add employees to the list
            employees.Add(employee1);
            employees.Add(employee2);
            employees.Add(employee3);
            employees.Add(employee5);
            employees.Add(employee7);


            int importanceCout = sol.GetImportance(employees, 1);

            System.Console.WriteLine(importanceCout);
            //    System.Console.WriteLine(sol.GetImportance());
        }

    }

}
namespace EmployeeImportance
{
    // Definition for Employee.
    public class Employee
    {
        public int id;
        public int importance;
        public IList<int> subordinates;


        // Constructor
        public Employee(int id, int importance)
        {
            this.id = id;
            this.importance = importance;
            this.subordinates = new List<int>();
        }

        // Method to add a subordinate
        public void AddSubordinate(int subordinateId)
        {
            subordinates.Add(subordinateId);
        }
    }

    class Solution
    {
        public int GetImportance(IList<Employee> employees, int id)
        {
            Dictionary<int, Employee> employeesGraph = new Dictionary<int, Employee>();
            foreach (var item in employees)
            {
                employeesGraph.Add(item.id, item);
            }
            int dfsVal = DFS(employeesGraph, id);
            return dfsVal;
        }

        private int DFS(Dictionary<int, Employee> employeesGraph, int id)
        {
            int importanceC = employeesGraph[id].importance;
            foreach (int item in employeesGraph[id].subordinates)
            {
                importanceC+= DFS(employeesGraph, item);
            }
            return importanceC  ;
        }
    }
   

}