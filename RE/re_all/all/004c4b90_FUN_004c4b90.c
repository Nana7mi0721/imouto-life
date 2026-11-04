
void __fastcall FUN_004c4b90(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  int local_8;
  
  local_8 = 0;
  while( true ) {
    iVar2 = FUN_004d3180(param_1);
    if (iVar2 <= local_8) break;
    FUN_004d31e0(local_8);
    FUN_004c4c50();
    iVar2 = FUN_004d31e0(local_8);
    if (*(char *)(iVar2 + 0x279) != '\0') {
      FUN_004d31e0(local_8);
      cVar1 = FUN_004cd380();
      if (cVar1 != '\0') {
        puVar4 = local_10;
        iVar2 = local_8;
        FUN_004ce060(local_c);
        puVar3 = (undefined4 *)FUN_004d3330(puVar4,iVar2);
        FUN_004d32a0(local_14,*puVar3);
        local_8 = local_8 + -1;
      }
    }
    local_8 = local_8 + 1;
  }
  FUN_0049ed50();
  return;
}

