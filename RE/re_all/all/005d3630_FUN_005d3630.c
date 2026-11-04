
undefined4 FUN_005d3630(void)

{
  if (DAT_00f3a054 != (int *)0x0) {
    (**(code **)(*DAT_00f3a054 + 8))(DAT_00f3a054);
    DAT_00f3a054 = (int *)0x0;
  }
  if (DAT_00f3a04c != (int *)0x0) {
    FUN_0056bb10(&PTR_LAB_007ff984);
    (**(code **)(*DAT_00f3a04c + 8))(DAT_00f3a04c);
    DAT_00f3a04c = (int *)0x0;
  }
  return 0;
}

