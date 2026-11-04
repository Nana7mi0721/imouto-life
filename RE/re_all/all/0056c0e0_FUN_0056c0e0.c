
undefined4 FUN_0056c0e0(void)

{
  int iVar1;
  undefined1 local_14 [20];
  
  if ((DAT_00ab012c == 0) && (iVar1 = FUN_0056c020(), iVar1 < 0)) {
    return 0;
  }
  if (DAT_00ab0138 != 0) {
    FUN_0052fd80(local_14);
    DAT_00ab0134 = FUN_00530090(local_14,0,DAT_00aba0a8,4,1,0xffffffff,0xffffffff,0,0xffffffff,0);
    if (-1 < DAT_00ab0134) {
      FUN_00536790(DAT_00ab0134,&DAT_00ab0138);
      DAT_00ab0138 = 0;
      return 0;
    }
    DAT_00ab0134 = 0xfffffffe;
    DAT_00ab0138 = 0;
  }
  return 0;
}

