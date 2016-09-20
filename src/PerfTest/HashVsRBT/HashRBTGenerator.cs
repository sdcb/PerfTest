using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace PerfTest.HashVsRBT
{
    public class HashRBTGenerator
    {
        public static Dictionary<string, string> CreateHashN(int size)
        {
            var dict = new Dictionary<string, string>();
            for (var i = 0; i < size; ++i)
            {
                dict[Guid.NewGuid().ToString()] = Guid.NewGuid().ToString();
            }
            return dict;
        }

        public static SortedDictionary<string, string> CreateRBTN(int size)
        {
            var dict = new SortedDictionary<string, string>();
            for (var i = 0; i < size; ++i)
            {
                dict[Guid.NewGuid().ToString()] = Guid.NewGuid().ToString();
            }
            return dict;
        }
    }
}
