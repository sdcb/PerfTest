using PerfTest.StructClass;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Threading.Tasks;

namespace PerfTest.StructClass
{
    public class StructClassTest
    {
        const int CaseSize = 20 * 1024 * 1024;

        public static void DoTest()
        {
            var pt = new StructClassTest();
            //pt.EmptyMemory();
            //pt.ClassMemoryTest();
            //pt.StructMemoryTest();

            //pt.ClassTimeTest();
            //pt.StructTimeTest();

            //pt.ClassGenerateTimeTest();
            //pt.StructGenerateTimeTest();
        }

        public void EmptyMemory()
        {
            Console.WriteLine(nameof(EmptyMemory));
            Console.WriteLine($"Memory: {GetCurrentProcessMemoryMb()} MB.");
        }
        
        public void ClassMemoryTest(int size = CaseSize)
        {
            Console.WriteLine(nameof(ClassMemoryTest));
            var buffer = Vector2C.CreateN(size).ToList();
            Console.WriteLine($"Memory: {GetCurrentProcessMemoryMb()} MB, size = {buffer.Count}.");
        }
        
        public void StructMemoryTest(int size = CaseSize)
        {
            Console.WriteLine(nameof(StructMemoryTest));
            var buffer = Vector2S.CreateN(size).ToList();
            Console.WriteLine($"Memory: {GetCurrentProcessMemoryMb()} MB, size = {buffer.Count}.");
        }
        
        public void ClassTimeTest(int size = CaseSize)
        {
            Console.WriteLine(nameof(ClassTimeTest));
            var buffer = Vector2C.CreateN(size).ToList();
            MeasureTime(() => buffer.Average(v => v.X + v.Y));
        }
        
        public void StructTimeTest(int size = CaseSize)
        {
            Console.WriteLine(nameof(StructTimeTest));
            var buffer = Vector2S.CreateN(size).ToList();
            MeasureTime(() => buffer.Average(v => v.X + v.Y));
        }

        public void StructGenerateTimeTest(int size = CaseSize)
        {
            Console.WriteLine(nameof(StructGenerateTimeTest));
            MeasureTime(() => Vector2S.CreateN(size).ToList());
        }

        public void ClassGenerateTimeTest(int size = CaseSize)
        {
            Console.WriteLine(nameof(ClassGenerateTimeTest));
            MeasureTime(() => Vector2C.CreateN(size).ToList());
        }

        private void MeasureTime<T>(Func<T> action)
        {
            var sw = new Stopwatch();
            sw.Start();
            var t = action();
            Console.WriteLine($"{sw.ElapsedMilliseconds}ms, result: {t}.");
        }

        private float GetCurrentProcessMemoryMb()
        {
            var ps = Process.GetCurrentProcess();
            return ps.WorkingSet64 / 1024.0f / 1024;
        }
    }
}
