
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00484bb0(void)

{
  undefined4 uVar1;
  int *piVar2;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_7c [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_60 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_44 [28];
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007af6b8;
  local_10 = ExceptionList;
  _DAT_00a16548 = &DAT_00a16538;
  _DAT_00a16540 = &DAT_00a143d8;
  _DAT_00a16544 = &DAT_00a14bb8;
  _DAT_00a14bc8 = &DAT_00a16538;
  _DAT_00a14bc0 = &DAT_00a143d8;
  _DAT_00a14bc4 = &DAT_00a14bb8;
  _DAT_00a143e8 = &DAT_00a16538;
  _DAT_00a143e0 = &DAT_00a143d8;
  _DAT_00a143e4 = &DAT_00a14bb8;
  ExceptionList = &local_10;
  for (local_1c = 0; local_1c < 3; local_1c = local_1c + 1) {
    if (local_1c == 0) {
      local_14 = &DAT_00a16538;
    }
    else if (local_1c == 1) {
      local_14 = &DAT_00a143d8;
    }
    else if (local_1c == 2) {
      local_14 = &DAT_00a14bb8;
    }
    local_18 = FUN_00477850();
    FUN_004ccc40();
    FUN_004cd070();
    FUN_004cd070();
    FUN_004ccfc0(local_18);
    FUN_004ccfc0(local_18);
    local_20 = local_18;
    while (local_20 = local_20 + -1, -1 < local_20) {
      uVar1 = FUN_00470f50(local_44,local_20);
      local_8 = 0;
      piVar2 = (int *)FUN_004cc680(uVar1);
      *piVar2 = local_20;
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_44);
      local_24 = FUN_004717c0(local_20);
      while (local_24 = local_24 + -1, -1 < local_24) {
        uVar1 = FUN_004706f0(local_60,local_20,local_24,0);
        local_8 = 1;
        FUN_004cd030(local_20);
        piVar2 = (int *)FUN_004cc680(uVar1);
        *piVar2 = local_24;
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_60);
      }
      local_28 = FUN_00477980(local_20);
      while (local_28 = local_28 + -1, -1 < local_28) {
        uVar1 = FUN_00471030(local_7c,local_20,local_28);
        local_8 = 2;
        FUN_004cd030(local_20);
        piVar2 = (int *)FUN_004cc680(uVar1);
        *piVar2 = local_28;
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_7c);
      }
    }
  }
  ExceptionList = local_10;
  return;
}

