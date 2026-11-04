
undefined4 * __thiscall FUN_004df500(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b1635;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  FUN_004dfd30(param_2 + 2);
  local_8 = 0;
  _eh_vector_copy_constructor_iterator_
            (param_1 + 0x4c,param_2 + 0x4c,0x10,2,FUN_004cdf90,FUN_004ce950);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x54),
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (param_2 + 0x54));
  local_8._0_1_ = 1;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x5b),
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (param_2 + 0x5b));
  local_8._0_1_ = 2;
  param_1[0x62] = param_2[0x62];
  param_1[99] = param_2[99];
  param_1[100] = param_2[100];
  param_1[0x65] = param_2[0x65];
  param_1[0x66] = param_2[0x66];
  param_1[0x67] = param_2[0x67];
  param_1[0x68] = param_2[0x68];
  param_1[0x69] = param_2[0x69];
  param_1[0x6a] = param_2[0x6a];
  param_1[0x6b] = param_2[0x6b];
  param_1[0x6c] = param_2[0x6c];
  param_1[0x6d] = param_2[0x6d];
  param_1[0x6e] = param_2[0x6e];
  param_1[0x6f] = param_2[0x6f];
  param_1[0x70] = param_2[0x70];
  param_1[0x71] = param_2[0x71];
  param_1[0x72] = param_2[0x72];
  param_1[0x73] = param_2[0x73];
  param_1[0x74] = param_2[0x74];
  param_1[0x75] = param_2[0x75];
  param_1[0x76] = param_2[0x76];
  param_1[0x77] = param_2[0x77];
  param_1[0x78] = param_2[0x78];
  param_1[0x79] = param_2[0x79];
  param_1[0x7a] = param_2[0x7a];
  param_1[0x7b] = param_2[0x7b];
  param_1[0x7c] = param_2[0x7c];
  param_1[0x7d] = param_2[0x7d];
  param_1[0x7e] = param_2[0x7e];
  param_1[0x7f] = param_2[0x7f];
  puVar2 = param_2 + 0x80;
  puVar3 = param_1 + 0x80;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = param_2 + 0x88;
  puVar3 = param_1 + 0x88;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined1 *)(param_1 + 0x90) = *(undefined1 *)(param_2 + 0x90);
  FUN_004cc180(param_2 + 0x91);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004cd0c0(param_2 + 0x95);
  *(undefined1 *)(param_1 + 0x99) = *(undefined1 *)(param_2 + 0x99);
  *(undefined1 *)((int)param_1 + 0x265) = *(undefined1 *)((int)param_2 + 0x265);
  *(undefined1 *)((int)param_1 + 0x266) = *(undefined1 *)((int)param_2 + 0x266);
  *(undefined1 *)((int)param_1 + 0x267) = *(undefined1 *)((int)param_2 + 0x267);
  *(undefined2 *)(param_1 + 0x9a) = *(undefined2 *)(param_2 + 0x9a);
  *(undefined2 *)((int)param_1 + 0x26a) = *(undefined2 *)((int)param_2 + 0x26a);
  param_1[0x9b] = param_2[0x9b];
  param_1[0x9c] = param_2[0x9c];
  param_1[0x9d] = param_2[0x9d];
  *(undefined1 *)(param_1 + 0x9e) = *(undefined1 *)(param_2 + 0x9e);
  *(undefined1 *)((int)param_1 + 0x279) = *(undefined1 *)((int)param_2 + 0x279);
  *(undefined1 *)((int)param_1 + 0x27a) = *(undefined1 *)((int)param_2 + 0x27a);
  param_1[0x9f] = param_2[0x9f];
  param_1[0xa0] = param_2[0xa0];
  param_1[0xa1] = param_2[0xa1];
  param_1[0xa2] = param_2[0xa2];
  param_1[0xa3] = param_2[0xa3];
  param_1[0xa4] = param_2[0xa4];
  param_1[0xa5] = param_2[0xa5];
  param_1[0xa6] = param_2[0xa6];
  param_1[0xa7] = param_2[0xa7];
  param_1[0xa8] = param_2[0xa8];
  param_1[0xa9] = param_2[0xa9];
  param_1[0xaa] = param_2[0xaa];
  param_1[0xab] = param_2[0xab];
  param_1[0xac] = param_2[0xac];
  param_1[0xad] = param_2[0xad];
  param_1[0xae] = param_2[0xae];
  param_1[0xaf] = param_2[0xaf];
  param_1[0xb0] = param_2[0xb0];
  param_1[0xb1] = param_2[0xb1];
  param_1[0xb2] = param_2[0xb2];
  param_1[0xb3] = param_2[0xb3];
  param_1[0xb4] = param_2[0xb4];
  param_1[0xb5] = param_2[0xb5];
  param_1[0xb6] = param_2[0xb6];
  param_1[0xb7] = param_2[0xb7];
  param_1[0xb8] = param_2[0xb8];
  param_1[0xb9] = param_2[0xb9];
  param_1[0xba] = param_2[0xba];
  param_1[0xbb] = param_2[0xbb];
  param_1[0xbc] = param_2[0xbc];
  param_1[0xbd] = param_2[0xbd];
  param_1[0xbe] = param_2[0xbe];
  param_1[0xbf] = param_2[0xbf];
  param_1[0xc0] = param_2[0xc0];
  param_1[0xc1] = param_2[0xc1];
  param_1[0xc2] = param_2[0xc2];
  param_1[0xc3] = param_2[0xc3];
  param_1[0xc4] = param_2[0xc4];
  param_1[0xc5] = param_2[0xc5];
  param_1[0xc6] = param_2[0xc6];
  param_1[199] = param_2[199];
  param_1[200] = param_2[200];
  param_1[0xc9] = param_2[0xc9];
  param_1[0xca] = param_2[0xca];
  param_1[0xcb] = param_2[0xcb];
  param_1[0xcc] = param_2[0xcc];
  param_1[0xcd] = param_2[0xcd];
  param_1[0xce] = param_2[0xce];
  param_1[0xcf] = param_2[0xcf];
  param_1[0xd0] = param_2[0xd0];
  param_1[0xd1] = param_2[0xd1];
  param_1[0xd2] = param_2[0xd2];
  param_1[0xd3] = param_2[0xd3];
  param_1[0xd4] = param_2[0xd4];
  param_1[0xd5] = param_2[0xd5];
  param_1[0xd6] = param_2[0xd6];
  param_1[0xd7] = param_2[0xd7];
  param_1[0xd8] = param_2[0xd8];
  param_1[0xd9] = param_2[0xd9];
  param_1[0xda] = param_2[0xda];
  param_1[0xdb] = param_2[0xdb];
  param_1[0xdc] = param_2[0xdc];
  param_1[0xdd] = param_2[0xdd];
  param_1[0xde] = param_2[0xde];
  param_1[0xdf] = param_2[0xdf];
  param_1[0xe0] = param_2[0xe0];
  param_1[0xe1] = param_2[0xe1];
  ExceptionList = local_10;
  return param_1;
}

