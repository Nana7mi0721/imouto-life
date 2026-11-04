
void __thiscall FUN_00472b10(int param_1,char param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_004d3310();
  *(undefined4 *)(param_1 + 0x10) = 0;
  for (local_8 = 0; local_8 < 0x20; local_8 = local_8 + 1) {
    *(undefined4 *)(param_1 + 0x14 + local_8 * 4) = 0;
  }
  if (param_2 != '\0') {
    FUN_004cc250();
    FUN_004ce950();
    local_c = 0;
    while( true ) {
      iVar1 = FUN_004ce080();
      if (iVar1 <= local_c) break;
      uVar3 = 0;
      puVar2 = (undefined4 *)FUN_004ce990(local_c);
      FUN_00515700(*puVar2,uVar3);
      local_10 = 0;
      while( true ) {
        FUN_004cde80(local_c);
        iVar1 = FUN_004ce080();
        if (iVar1 <= local_10) break;
        uVar3 = 0;
        iVar1 = local_10;
        FUN_004cde80(local_c);
        puVar2 = (undefined4 *)FUN_004ce990(iVar1);
        FUN_00515700(*puVar2,uVar3);
        local_10 = local_10 + 1;
      }
      local_c = local_c + 1;
    }
    FUN_004ce950();
    FUN_004ce950();
    FUN_004ce950();
    FUN_004cd4c0();
    FUN_004ce950();
    FUN_004ce950();
  }
  return;
}

