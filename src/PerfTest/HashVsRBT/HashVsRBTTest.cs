using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Threading.Tasks;

namespace PerfTest.HashVsRBT
{
    public class HashVsRBTTest
    {
        const int CaseSize = 200 * 1024;

        public static void DoTest()
        {
            var t = new HashVsRBTTest();

            t.HashCreateTest();
            t.RBTCreateTest();
            t.HashFindTest();
            t.RBTFindTest();
        }

        void HashCreateTest()
        {
            Console.WriteLine(nameof(HashCreateTest));
            var v = MeasureTime(() => HashRBTGenerator.CreateHashN(CaseSize));
            Console.WriteLine($"size: {v.Count}.");
        }

        void RBTCreateTest()
        {
            Console.WriteLine(nameof(RBTCreateTest));
            var v = MeasureTime(() => HashRBTGenerator.CreateRBTN(CaseSize));
            Console.WriteLine($"size: {v.Count}.");
        }

        void HashFindTest()
        {
            Console.WriteLine(nameof(HashFindTest));
            var buffer = HashRBTGenerator.CreateHashN(CaseSize);
            var v = MeasureTime(() =>
            {
                for (var i = 0; i < CaseSize; ++i)
                {
                    buffer.ContainsKey(Guid.NewGuid().ToString());
                }
                return 0;
            });
        }

        void RBTFindTest()
        {
            Console.WriteLine(nameof(RBTFindTest));
            var buffer = HashRBTGenerator.CreateRBTN(CaseSize);
            var v = MeasureTime(() =>
            {
                for (var i = 0; i < CaseSize; ++i)
                {
                    buffer.ContainsKey(Guid.NewGuid().ToString());
                }
                return 0;
            });
        }

        private T MeasureTime<T>(Func<T> action)
        {
            var sw = new Stopwatch();
            sw.Start();
            var t = action();
            Console.WriteLine($"{sw.ElapsedMilliseconds}ms.");
            return t;
        }
    }
}
