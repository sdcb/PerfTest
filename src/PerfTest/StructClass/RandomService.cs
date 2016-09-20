using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace PerfTest.StructClass
{
    public static class RandomService
    {
        private static Random r = new Random();

        public static int Next(int max)
        {
            return r.Next(max);
        }
    }
}
