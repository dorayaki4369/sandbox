using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography.Xml;
using System.Text.Json;
using System.Windows;
using System.Windows.Documents;
using System.Windows.Navigation;
using DragAndList.Models;
using GongSolutions.Wpf.DragDrop;
using Prism.Mvvm;
using Reactive.Bindings;
using DataObject = System.Windows.DataObject;

namespace DragAndList.ViewModels
{
    public class MainWindowViewModel : BindableBase, IDropTarget
    {
        private string _title = "DragAndList";

        public string Title
        {
            get => _title;
            set => SetProperty(ref _title, value);
        }

        private string _description = "Please drop a JSON file into the here.";

        public string Description
        {
            get => _description;
            set => SetProperty(ref _description, value);
        }

        public ReactiveProperty<string> JsonFilePath { get; } = new ReactiveProperty<string>("");

        public ReactiveProperty<CompanyData> CompanyData { get;} = new ReactiveProperty<CompanyData>();


        public MainWindowViewModel()
        {
            JsonFilePath.Subscribe(_ =>
            {
                if (!File.Exists(JsonFilePath.Value)) return;
                var jsonString  = File.ReadAllText(JsonFilePath.Value);
                CompanyData.Value = JsonSerializer.Deserialize<CompanyData>(jsonString);
            });
        }

        public void DragOver(IDropInfo dropInfo)
        {
            var files = ((DataObject) dropInfo.Data).GetFileDropList()
                                                    .Cast<string>();
            dropInfo.Effects = files.Any(f => f.EndsWith(".json")) ? DragDropEffects.Copy : DragDropEffects.None;
        }

        public void Drop(IDropInfo dropInfo)
        {
            var files = ((DataObject) dropInfo.Data).GetFileDropList()
                                                    .Cast<string>()
                                                    .Where(f => f.EndsWith(".json"))
                                                    .ToList();

            if (files.Count != 1) return;

            JsonFilePath.Value = files.First();
        }
    }
}