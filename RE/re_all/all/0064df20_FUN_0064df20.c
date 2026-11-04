
undefined4 FUN_0064df20(int *param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  
  puVar1 = (undefined1 *)FUN_006507d0(0x10000);
  param_1[0x14] = (int)puVar1;
  if (puVar1 == (undefined1 *)0x0) {
    FUN_006512e0(*(undefined4 *)(*param_1 + 0x274),"BuildMapBitdepth16To8",s_Out_of_memory_00a066e4)
    ;
    return 0;
  }
  uVar2 = 0;
  do {
    *puVar1 = (char)((uVar2 + 0x80) / 0x101);
    puVar1 = puVar1 + 1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x10000);
  return 1;
}

