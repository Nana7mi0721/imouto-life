
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0059ee20(void)

{
  undefined4 uVar1;
  undefined1 local_130 [196];
  uint local_6c;
  uint local_64;
  
  if ((DAT_00f3a04c != 0) && (DAT_00a37dc8 != 0)) {
    FUN_005d3480(-(uint)(DAT_00a37eec != 0) & _DAT_00a37ef0,1,local_130);
    if ((0x1ff < (local_6c & 0xffff)) || (0x1ff < (local_64 & 0xffff))) {
      if (((local_6c & 0xffff) < 0x300) || (uVar1 = 300, (local_64 & 0xffff) < 0x300)) {
        uVar1 = 200;
      }
      return uVar1;
    }
  }
  return 0;
}

