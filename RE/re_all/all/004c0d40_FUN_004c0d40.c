
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __fastcall FUN_004c0d40(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0c2c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = FUN_004bd7f0(&DAT_00a14438);
  local_8 = 0;
  FUN_004c1080(uVar1);
  local_8 = 0xffffffff;
  FUN_004c0f80();
  FUN_004d3bd0(DAT_0084b21c);
  for (local_14 = 0; local_14 < DAT_0084b21c; local_14 = local_14 + 1) {
    uVar1 = FUN_004d2620(local_14);
    uVar1 = FUN_004bd7f0(uVar1);
    local_8 = 1;
    FUN_004d3c00(local_14);
    FUN_004c1080(uVar1);
    local_8 = 0xffffffff;
    FUN_004c0f80();
  }
  FUN_004d3cb0();
  local_18 = 0;
  while( true ) {
    iVar2 = FUN_004d29a0();
    if (iVar2 <= local_18) break;
    uVar1 = FUN_004d2a00(local_18);
    uVar1 = FUN_004bd7f0(uVar1);
    local_8 = 2;
    FUN_004d3c40(uVar1);
    local_8 = 0xffffffff;
    FUN_004c0f80();
    local_18 = local_18 + 1;
  }
  uVar1 = FUN_004c0290();
  local_8 = 3;
  FUN_004c11c0(uVar1);
  local_8 = 0xffffffff;
  FUN_004c0fa0();
  puVar3 = (undefined4 *)FUN_004c0bb0();
  puVar4 = (undefined4 *)(param_1 + 0x9f40);
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar3 = (undefined4 *)FUN_004c0c10();
  puVar4 = (undefined4 *)(param_1 + 0x9f70);
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  ExceptionList = local_10;
  return;
}

