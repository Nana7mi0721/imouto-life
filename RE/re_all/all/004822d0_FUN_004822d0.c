
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004822d0(char param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int local_140 [73];
  int local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007af54e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = FUN_004718a0();
  local_8 = 0;
  FUN_00472740(uVar1);
  local_8 = 0xffffffff;
  FUN_00484b30();
  uVar1 = FUN_004718a0();
  local_8 = 1;
  FUN_00472740(uVar1);
  local_8 = 0xffffffff;
  FUN_00484b30();
  _DAT_00a14bbc = 0;
  _DAT_00a143dc = 2;
  FUN_004825c0("BasicData/SysDataBase");
  FUN_004825c0("BasicData/DataBase");
  iVar2 = FUN_004717c0(1);
  FUN_004779b0(1,iVar2 + 10);
  iVar2 = FUN_004717c0(2);
  FUN_004779b0(2,iVar2 + 10);
  iVar2 = FUN_004717c0(3);
  FUN_004779b0(3,iVar2 + 10);
  if (param_1 == '\0') {
    uVar1 = FUN_004718a0();
    local_8 = 2;
    FUN_00472740(uVar1);
    local_8 = 0xffffffff;
    FUN_00484b30();
    _DAT_00a1653c = 1;
    FUN_004825c0("BasicData/CDataBase");
    FUN_004cd4c0();
    uVar1 = FUN_00477850();
    FUN_004cd310(uVar1);
    FUN_004cd4c0();
    uVar1 = FUN_00477850();
    FUN_004cd310(uVar1);
    FUN_004ce950();
    local_14 = 0;
    while (iVar2 = FUN_00477850(), local_14 < iVar2) {
      local_18 = FUN_004717c0(local_14);
      FUN_004ce160(&local_18);
      local_1c = 0;
      while( true ) {
        FUN_004d0120(local_14);
        iVar2 = FUN_004ce080();
        if (iVar2 <= local_1c) break;
        iVar2 = local_1c;
        FUN_004d0120(local_14);
        piVar3 = (int *)FUN_004ce990(iVar2);
        local_140[0] = *piVar3 / 1000;
        piVar3 = local_140;
        FUN_004cde80(local_14);
        FUN_004ce160(piVar3);
        iVar2 = local_1c;
        FUN_004d05c0(local_14);
        uVar1 = FUN_004ce990(iVar2);
        FUN_004cde80(local_14);
        FUN_004ce160(uVar1);
        local_1c = local_1c + 1;
      }
      local_14 = local_14 + 1;
    }
  }
  ExceptionList = local_10;
  return;
}

