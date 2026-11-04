
undefined4 FUN_0064f620(int param_1,ushort *param_2,uint *param_3)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  ushort *puVar4;
  uint uVar5;
  
  uVar1 = *param_2;
  uVar3 = (uint)uVar1;
  *param_3 = uVar3;
  if (*(ushort *)(param_1 + 0x3a) < uVar1) {
    return 0;
  }
  puVar2 = *(ushort **)(param_2 + 2);
  if ((uVar3 != 0) && (puVar2 == (ushort *)0x0)) {
    return 0;
  }
  uVar5 = 0;
  if (uVar3 != 0) {
    puVar4 = puVar2;
    do {
      if (2 < *puVar4) {
        if (*puVar4 != 999) {
          return 0;
        }
        *puVar4 = 2;
      }
      uVar5 = uVar5 + 1;
      puVar4 = puVar4 + 1;
    } while (uVar5 < *param_3);
  }
  uVar3 = *param_3;
  *(short *)(param_1 + 0x74) = (short)uVar3;
  FUN_0064e170(param_1 + 0x78,puVar2,(short)uVar3);
  return 1;
}

