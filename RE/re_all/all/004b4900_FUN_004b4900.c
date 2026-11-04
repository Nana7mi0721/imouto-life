
undefined1 * __thiscall FUN_004b4900(undefined1 *param_1,undefined1 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b04d3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = *param_2;
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
  param_1[0xc] = param_2[0xc];
  param_1[0xd] = param_2[0xd];
  param_1[0xe] = param_2[0xe];
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 0x14);
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_2 + 0x18);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_2 + 0x20);
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_2 + 0x24);
  FUN_004d1f60(param_2 + 0x28);
  local_8 = 0;
  puVar2 = (undefined4 *)(param_2 + 0x38);
  puVar3 = (undefined4 *)(param_1 + 0x38);
  for (iVar1 = 500; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(param_1 + 0x808) = *(undefined4 *)(param_2 + 0x808);
  FUN_004cea00(param_2 + 0x80c);
  local_8._0_1_ = 1;
  FUN_004cf820(param_2 + 0x81c);
  local_8._0_1_ = 2;
  *(undefined4 *)(param_1 + 0x82c) = *(undefined4 *)(param_2 + 0x82c);
  FUN_004cdf90(param_2 + 0x830);
  local_8._0_1_ = 3;
  FUN_004cdf90(param_2 + 0x840);
  local_8 = CONCAT31(local_8._1_3_,4);
  param_1[0x850] = param_2[0x850];
  *(undefined4 *)(param_1 + 0x854) = *(undefined4 *)(param_2 + 0x854);
  *(undefined4 *)(param_1 + 0x858) = *(undefined4 *)(param_2 + 0x858);
  *(undefined4 *)(param_1 + 0x85c) = *(undefined4 *)(param_2 + 0x85c);
  *(undefined4 *)(param_1 + 0x860) = *(undefined4 *)(param_2 + 0x860);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x864),
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (param_2 + 0x864));
  *(undefined4 *)(param_1 + 0x880) = *(undefined4 *)(param_2 + 0x880);
  *(undefined4 *)(param_1 + 0x884) = *(undefined4 *)(param_2 + 0x884);
  *(undefined4 *)(param_1 + 0x888) = *(undefined4 *)(param_2 + 0x888);
  *(undefined4 *)(param_1 + 0x88c) = *(undefined4 *)(param_2 + 0x88c);
  *(undefined4 *)(param_1 + 0x890) = *(undefined4 *)(param_2 + 0x890);
  *(undefined4 *)(param_1 + 0x894) = *(undefined4 *)(param_2 + 0x894);
  *(undefined4 *)(param_1 + 0x898) = *(undefined4 *)(param_2 + 0x898);
  *(undefined4 *)(param_1 + 0x89c) = *(undefined4 *)(param_2 + 0x89c);
  *(undefined4 *)(param_1 + 0x8a0) = *(undefined4 *)(param_2 + 0x8a0);
  param_1[0x8a4] = param_2[0x8a4];
  ExceptionList = local_10;
  return param_1;
}

