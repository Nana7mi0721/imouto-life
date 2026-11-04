
void __thiscall FUN_004a5440(undefined4 *param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_40 [44];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007afbc0;
  local_10 = ExceptionList;
  if (param_3 < 1) {
    if (*(char *)(param_1 + 0x9e) == '\0') {
      ExceptionList = &local_10;
      param_1[0x6c] = param_2;
      param_1[0x6d] = param_2;
      for (local_14 = 0; local_14 < 3; local_14 = local_14 + 1) {
        param_1[local_14 + 0x7b] = param_1[local_14 + 0x78];
      }
      if ((param_4 & 0x1000000) == 0) {
        uVar1 = FUN_004fe844();
        param_1[0x78] = uVar1;
        uVar1 = FUN_004fe844();
        param_1[0x79] = uVar1;
        uVar1 = FUN_004fe844();
        param_1[0x7a] = uVar1;
      }
      *(undefined1 *)(param_1 + 0x9e) = 1;
      if ((int)param_1[0x6c] < 1) {
        *(undefined1 *)((int)param_1 + 0x279) = 1;
        *param_1 = 0;
        param_1[1] = *param_1;
      }
    }
  }
  else {
    ExceptionList = &local_10;
    uVar1 = FUN_004cdf50(0);
    local_8 = 0;
    FUN_004cd3f0(uVar1);
    local_8 = 0xffffffff;
    FUN_004ce950();
    basic_string<>(&DAT_007d0621);
    local_8 = 1;
    FUN_004cc500(local_40);
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_40);
    iVar2 = FUN_004cd340();
    FUN_004cde80(iVar2 + -1);
    FUN_004ce950();
    puVar3 = &param_3;
    iVar2 = FUN_004cd340(puVar3);
    FUN_004cde80(iVar2 + -1);
    FUN_004ce160(puVar3);
    local_44 = 3;
    puVar3 = &local_44;
    iVar2 = FUN_004cd340(puVar3);
    FUN_004cde80(iVar2 + -1);
    FUN_004ce160(puVar3);
    puVar3 = &param_2;
    iVar2 = FUN_004cd340(puVar3);
    FUN_004cde80(iVar2 + -1);
    FUN_004ce160(puVar3);
    puVar3 = &param_4;
    iVar2 = FUN_004cd340(puVar3);
    FUN_004cde80(iVar2 + -1);
    FUN_004ce160(puVar3);
  }
  ExceptionList = local_10;
  return;
}

