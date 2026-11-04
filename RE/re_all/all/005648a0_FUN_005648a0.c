
undefined1 FUN_005648a0(int param_1)

{
  ushort *puVar1;
  undefined1 uVar2;
  int iVar3;
  ushort uVar4;
  ushort local_20;
  ushort local_1e;
  undefined2 local_1c;
  
  if (DAT_00aa4fdc == 0) {
    do {
      if (DAT_00aa57e8 == DAT_00aa57e4) {
        local_20 = 0;
      }
      else {
        puVar1 = &DAT_00aa4fe0 + DAT_00aa57e4;
        DAT_00aa57e4 = DAT_00aa57e4 + 1;
        if (DAT_00aa57e4 == 0x401) {
          DAT_00aa57e4 = 0;
        }
        if (*puVar1 == 0xffffffff) {
          FUN_0056bb10(&DAT_007d6bdc);
          local_20 = 0xffff;
        }
        else {
          local_20 = *puVar1;
        }
      }
      local_1e = 0;
      if (local_20 == 0) {
        return 0;
      }
      if ((local_20 & 0xfc00) == 0xd800) {
        if (DAT_00aa57e8 == DAT_00aa57e4) {
          uVar4 = 0;
        }
        else {
          uVar4 = (&DAT_00aa4fe0)[DAT_00aa57e4];
          DAT_00aa57e4 = DAT_00aa57e4 + 1;
          if (DAT_00aa57e4 == 0x401) {
            DAT_00aa57e4 = 0;
          }
          if (uVar4 == 0xffffffff) {
            FUN_0056bb10(&DAT_007d6bdc);
            uVar4 = 0xffff;
          }
        }
        local_1c = 0;
        local_1e = uVar4;
      }
      if (DAT_00aba24c == 0) {
        FUN_0057a980();
      }
      iVar3 = DAT_00aba24c;
      if (DAT_00aba250 == 0) {
        FUN_0057a980();
      }
      DAT_00aa4fdc = FUN_005764b0(&local_20,0xffffffff,DAT_00aba250,&DAT_00aa4fcc,0x10,iVar3);
    } while (0 < DAT_00aa4fdc);
  }
  uVar2 = DAT_00aa4fcc;
  if ((param_1 != 0) && (DAT_00aa4fdc = DAT_00aa4fdc + -1, 0 < DAT_00aa4fdc)) {
    FUN_0056d460(&DAT_00aa4fcc,&DAT_00aa4fcd,DAT_00aa4fdc);
  }
  return uVar2;
}

