
undefined4 FUN_00584010(void)

{
  if (DAT_00dccde0 != '\0') {
    FUN_00580eb0(0xe,0);
    FUN_00580eb0(0xd,0);
    if (DAT_00dda450 != 0) {
      FUN_0056e1d0(DAT_00dda450);
      DAT_00dda450 = 0;
      DAT_00dda454 = 0;
    }
    FUN_005db610();
    FUN_00581030(0xe);
    FUN_00581030(0xd);
    DAT_00dccde0 = '\0';
  }
  return 0;
}

