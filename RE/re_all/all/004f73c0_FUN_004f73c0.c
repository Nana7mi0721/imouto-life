
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004f73c0(undefined4 *param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *pbVar5;
  short local_18;
  int local_c;
  int local_8;
  
  FUN_004cf7d0();
  iVar2 = FUN_004cc430();
  if (iVar2 != 0) {
    FUN_004cc4c0();
    iVar2 = FUN_004e5650();
    if (iVar2 != 0) goto LAB_004f77ae;
  }
  uVar3 = FUN_004cd7c0();
  param_1[0x13] = uVar3;
  uVar3 = FUN_004cd7c0();
  param_1[0x14] = uVar3;
  uVar3 = FUN_004cd7c0();
  param_1[0x15] = uVar3;
  uVar3 = FUN_004cd7c0();
  param_1[0x16] = uVar3;
  uVar3 = FUN_004cd7c0();
  param_1[0x17] = uVar3;
  uVar3 = FUN_004cd7c0();
  param_1[0x18] = uVar3;
  uVar3 = FUN_004cd7c0();
  param_1[0x19] = uVar3;
  uVar3 = FUN_004cd7c0();
  param_1[0x1a] = uVar3;
  uVar3 = FUN_004cd7c0();
  param_1[0x1b] = uVar3;
  uVar3 = FUN_004cd7c0();
  param_1[0x1c] = uVar3;
  uVar3 = FUN_004cd7c0();
  param_1[0x1d] = uVar3;
  uVar3 = FUN_004cd7c0();
  param_1[0x1e] = uVar3;
  uVar3 = FUN_004cd7c0();
  param_1[0x1f] = uVar3;
  uVar3 = FUN_004cd7c0();
  param_1[0x20] = uVar3;
  uVar3 = FUN_004cd7c0();
  param_1[0x21] = uVar3;
  uVar3 = FUN_004cd7c0();
  param_1[0x22] = uVar3;
  uVar3 = FUN_004cd7c0();
  param_1[0x23] = uVar3;
  uVar3 = FUN_004cd7c0();
  param_1[0x24] = uVar3;
  uVar3 = FUN_004cd7c0();
  param_1[0x25] = uVar3;
  uVar3 = FUN_004cd7c0();
  param_1[0x26] = uVar3;
  uVar3 = FUN_004cd7c0();
  param_1[0x27] = uVar3;
  uVar3 = FUN_004cd7c0();
  param_1[0x28] = uVar3;
  FUN_004cc400();
  uVar3 = FUN_004cc4c0();
  param_1[0x43] = uVar3;
  uVar3 = FUN_004cc4c0();
  param_1[0x44] = uVar3;
  uVar3 = FUN_004cc4c0();
  param_1[0x45] = uVar3;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::resize
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)param_1[0x45],0xc);
  uVar3 = FUN_004cc4c0();
  param_1[0x46] = uVar3;
  uVar3 = FUN_004cc4c0();
  param_1[0x47] = uVar3;
  uVar3 = FUN_004cc4c0();
  param_1[0x48] = uVar3;
  uVar3 = FUN_004cc4c0();
  param_1[0x49] = uVar3;
  uVar3 = FUN_004cc4c0();
  param_1[0x4a] = uVar3;
  uVar3 = FUN_004cc4c0();
  param_1[0x4b] = uVar3;
  FUN_004d0c40();
  uVar3 = FUN_004d0cd0();
  *param_1 = uVar3;
  for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
    uVar3 = FUN_004d0cd0();
    param_1[local_8 + 0x2d] = uVar3;
    uVar3 = FUN_004d0cd0();
    param_1[local_8 + 0x34] = uVar3;
  }
  uVar3 = FUN_004d0cd0();
  param_1[0x3b] = uVar3;
  uVar3 = FUN_004d0cd0();
  param_1[0x3c] = uVar3;
  uVar3 = FUN_004d0cd0();
  param_1[0x3d] = uVar3;
  uVar3 = FUN_004d0cd0();
  param_1[0x3e] = uVar3;
LAB_004f77ae:
  iVar2 = _rand();
  if (iVar2 % 10 < 5) {
    iVar2 = _rand();
    local_18 = (short)(iVar2 % 30000) + 0x3c8d;
  }
  else {
    iVar2 = _rand();
    local_18 = (short)(iVar2 % 15000);
  }
  *(short *)*param_1 = local_18;
  *(undefined1 *)param_1[0x13] = 0x20;
  *(undefined1 *)param_1[0x14] = 8;
  *(undefined1 *)param_1[0x15] = 8;
  *(undefined1 *)param_1[0x16] = 1;
  *(undefined1 *)param_1[0x18] = 1;
  *(undefined1 *)param_1[0x19] = 0;
  *(undefined1 *)param_1[0x1a] = 3;
  *(undefined1 *)param_1[0x1b] = 0;
  *(undefined1 *)param_1[0x1c] = 0;
  *(undefined1 *)param_1[0x1d] = 0;
  *(undefined1 *)param_1[0x1e] = 6;
  *(undefined1 *)param_1[0x1f] = 6;
  *(undefined1 *)param_1[0x20] = 0;
  *(undefined1 *)param_1[0x21] = 0;
  *(undefined1 *)param_1[0x22] = 4;
  *(undefined1 *)param_1[0x23] = 4;
  *(undefined1 *)param_1[0x24] = 1;
  *(undefined1 *)param_1[0x25] = 0;
  *(undefined1 *)param_1[0x26] = 1;
  *(undefined1 *)param_1[0x27] = 0;
  *(undefined1 *)param_1[0x28] = 0;
  for (local_c = 0; local_c < 7; local_c = local_c + 1) {
    FUN_0047eca0();
    uVar1 = FUN_004fe844();
    *(undefined2 *)param_1[local_c + 0x2d] = uVar1;
    FUN_0047eca0();
    uVar1 = FUN_004fe844();
    *(undefined2 *)param_1[local_c + 0x34] = uVar1;
  }
  *(undefined2 *)param_1[0x3b] = 10000;
  *(undefined2 *)param_1[0x3c] = 0x280;
  *(undefined2 *)param_1[0x3d] = 0x1e0;
  *(undefined2 *)param_1[0x3e] = 0xde;
  basic_string<>(&DAT_007d22a8);
  pcVar4 = (char *)FUN_00401c50();
  pbVar5 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)FUN_004cc4c0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(pbVar5,pcVar4);
  pcVar4 = "0000-0000";
  pbVar5 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)FUN_004cc4c0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(pbVar5,pcVar4);
  pcVar4 = "";
  pbVar5 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)FUN_004cc4c0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(pbVar5,pcVar4);
  pcVar4 = "";
  pbVar5 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)FUN_004cc4c0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(pbVar5,pcVar4);
  return;
}

