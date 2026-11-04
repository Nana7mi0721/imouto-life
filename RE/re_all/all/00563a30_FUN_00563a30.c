
undefined4 FUN_00563a30(void)

{
  int iVar1;
  int *local_4;
  
  if (DAT_00aae0bc != (int *)0x0) {
    if ((DAT_00aae0c0 != (int *)0x0) &&
       (iVar1 = (**(code **)*DAT_00aae0bc)(DAT_00aae0bc,&DAT_0085ef14,&local_4), -1 < iVar1)) {
      (**(code **)(*local_4 + 0x10))(local_4,DAT_00aae0c8);
      (**(code **)(*local_4 + 8))(local_4);
    }
    (**(code **)(*DAT_00aae0bc + 0x10))(DAT_00aae0bc);
    (**(code **)(*DAT_00aae0bc + 8))(DAT_00aae0bc);
    DAT_00aae0bc = (int *)0x0;
    if (DAT_00aae0c0 != (int *)0x0) {
      (**(code **)(*DAT_00aae0c0 + 8))(DAT_00aae0c0);
      DAT_00aae0c0 = (int *)0x0;
    }
  }
  return 0;
}

