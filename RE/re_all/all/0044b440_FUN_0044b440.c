
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0044b440(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined *puVar4;
  undefined1 auStack_5c [20];
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  undefined1 *local_30;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ad7e9;
  local_10 = ExceptionList;
  local_18 = *(undefined4 *)(param_1 + 0x165c);
  local_14 = *(undefined4 *)(param_1 + 0x1660);
  uStack_44 = 0x44b480;
  ExceptionList = &local_10;
  local_34 = param_1;
  FUN_004ccc40();
  uStack_44 = 0x44b48a;
  FUN_004ccc40();
  uStack_44 = 0x44b492;
  uStack_44 = FUN_00471820();
  local_8 = 0;
  uStack_48 = 0x44b4b0;
  local_3c = uStack_44;
  local_38 = uStack_44;
  FUN_00473710();
  local_8 = 0xffffffff;
  uStack_44 = 0x44b4bf;
  FUN_0047a000();
  local_30 = auStack_5c;
  local_40 = basic_string<>("BasicData/CommonEvent.dat");
  FUN_0047ecc0();
  FUN_004ccc40();
  local_1c = 0;
  while( true ) {
    iVar2 = FUN_004cfab0();
    if (iVar2 <= local_1c) break;
    puVar4 = &DAT_007ceb46;
    iVar2 = FUN_004cfb40(local_1c);
    cVar1 = operator!=<>(iVar2 + 4,puVar4);
    if (cVar1 != '\0') {
      iVar2 = FUN_004cfb40(local_1c);
      piVar3 = (int *)FUN_004cc680(iVar2 + 4);
      *piVar3 = local_1c;
    }
    local_1c = local_1c + 1;
  }
  DAT_00a18a94 = 0xffffffff;
  FUN_004822d0(1);
  FUN_00484bb0();
  FUN_00436d00();
  FUN_00481430("BasicData/TileSetData.dat");
  FUN_0047db00();
  FUN_0044ea60(0,1);
  _DAT_00a143e0 = &DAT_00a143d8;
  _DAT_00a143e4 = &DAT_00a14bb8;
  _DAT_00a143e8 = &DAT_00a16538;
  _DAT_00a14bc0 = &DAT_00a143d8;
  _DAT_00a14bc4 = &DAT_00a14bb8;
  _DAT_00a14bc8 = &DAT_00a16538;
  _DAT_00a16540 = &DAT_00a143d8;
  _DAT_00a16544 = &DAT_00a14bb8;
  _DAT_00a16548 = &DAT_00a16538;
  FUN_00449500(*(undefined4 *)(local_34 + 0x1658));
  FUN_00449cc0();
  *(undefined4 *)(local_34 + 0x165c) = local_18;
  *(undefined4 *)(local_34 + 0x1660) = local_14;
  ExceptionList = local_10;
  return;
}

