using System;
using System.Collections.Generic;
using System.Text;
using Reactive.Bindings;

namespace DragAndList.Models
{
    public class CompanyData
    {
        public List<Employee> Employees { get; set; }
    }
    public class Employee
    {
        public string Name   { get; set; }
        public int    Age    { get; set; }
        public string Notice { get; set; }
    }
}
