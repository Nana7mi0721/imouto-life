
void __thiscall
FUN_004787b0(int param_1,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_2)

{
  undefined4 uVar1;
  int iVar2;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007af318;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_004cb840(&param_2);
  *(undefined2 *)(param_1 + 0x50) = 0;
  local_14 = FUN_004cbbc0("T.png",0);
  if (local_14 == DAT_007d0624) {
    local_14 = FUN_004cbbc0("T.PNG",0);
    if (local_14 != DAT_007d0624) goto LAB_00478827;
  }
  else {
LAB_00478827:
    uVar1 = FUN_004cbb30(local_14);
    iVar2 = FUN_0046f680(uVar1);
    if (iVar2 == 0) {
      *(undefined2 *)(param_1 + 0x50) = 1;
    }
  }
  iVar2 = FUN_004cbbc0("TX.png",0);
  if (iVar2 == DAT_007d0624) {
    iVar2 = FUN_004cbbc0("TX.PNG",0);
    if (iVar2 != DAT_007d0624) goto LAB_0047887a;
  }
  else {
LAB_0047887a:
    *(undefined2 *)(param_1 + 0x50) = 2;
  }
  iVar2 = FUN_004cbbc0("$.png",0);
  if (iVar2 == DAT_007d0624) {
    iVar2 = FUN_004cbbc0("$.PNG",0);
    if (iVar2 == DAT_007d0624) goto LAB_004788ba;
  }
  *(undefined2 *)(param_1 + 0x50) = 0xffff;
LAB_004788ba:
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
  ExceptionList = local_10;
  return;
}

