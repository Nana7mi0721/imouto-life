
undefined ** FUN_00653cc0(short param_1)

{
  undefined4 *puVar1;
  undefined *puVar2;
  undefined **ppuVar3;
  
  for (puVar1 = DAT_00f3fa60; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
    if (*(short *)(puVar1[1] + 4) == param_1) {
      return (undefined **)puVar1[1];
    }
  }
  ppuVar3 = &PTR_DAT_00a0a8f8;
  puVar2 = PTR_DAT_00a0a8f8;
  while( true ) {
    if (puVar2 == (undefined *)0x0) {
      return (undefined **)0x0;
    }
    if (*(short *)(ppuVar3 + 1) == param_1) break;
    puVar2 = ppuVar3[3];
    ppuVar3 = ppuVar3 + 3;
  }
  return ppuVar3;
}

