using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace PerfTest.StructClass
{
    public struct Vector2S
    {
        public int X;

        public int Y;

        public static Vector2S CreateRandom()
        {
            return new Vector2S
            {
                X = RandomService.Next(10),
                Y = RandomService.Next(10)
            };
        }

        public static IEnumerable<Vector2S> CreateN(int n)
        {
            for (var i = 0; i < n; ++i)
            {
                yield return CreateRandom();
            }
        }
    }
}
