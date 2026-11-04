
_String_val<char,std::allocator<char>_> * __thiscall
FUN_004cf2d0(_String_val<char,std::allocator<char>_> *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uStack_40;
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 *local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b1000;
  pvStack_10 = ExceptionList;
  local_14 = local_20 + -0x1c;
  local_18 = (undefined1 *)&uStack_40;
  ExceptionList = &pvStack_10;
  uStack_40 = param_1;
  allocator<>(param_2);
  std::_String_val<char,std::allocator<char>_>::_String_val<char,std::allocator<char>_>(param_1);
  uStack_40 = (_String_val<char,std::allocator<char>_> *)0x4cf314;
  uStack_40 = (_String_val<char,std::allocator<char>_> *)FUN_004cf550();
  cVar1 = FUN_004d9670();
  if (cVar1 != '\0') {
    local_8 = 0;
    uStack_40 = (_String_val<char,std::allocator<char>_> *)local_1c;
    puVar2 = (undefined4 *)FUN_004dcb10();
    uStack_40 = (_String_val<char,std::allocator<char>_> *)local_20;
    puVar3 = (undefined4 *)FUN_004d8800();
    uStack_40 = *(_String_val<char,std::allocator<char>_> **)(param_1 + 4);
    uVar4 = DoMessageBox(*puVar3,*puVar2);
    *(undefined4 *)(param_1 + 8) = uVar4;
  }
  ExceptionList = pvStack_10;
  return param_1;
}

