using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace PerfTest.StructClass
{
    public class Vector2C
    {
        public int X;

        public int Y;

        public static Vector2C CreateRandom()
        {
            return new Vector2C
            {
                X = RandomService.Next(10), 
                Y = RandomService.Next(10)
            };
        }

        public static IEnumerable<Vector2C> CreateN(int n)
        {
            for (var i = 0; i < n; ++i)
            {
                yield return CreateRandom();
            }
        }
    }
}
