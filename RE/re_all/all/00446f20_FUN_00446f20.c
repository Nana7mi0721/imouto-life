
void __fastcall FUN_00446f20(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_3c [12];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  int iStack_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined1 *local_14;
  undefined1 *local_10;
  int local_c;
  int local_8;
  
  local_8 = -1;
  local_18 = param_1;
  if (*(char *)(param_1 + 0xbe) == '\0') {
    iStack_24 = 0x446f4c;
    local_c = FUN_004cf130();
    do {
      local_c = local_c + -1;
      if (local_c < 0) goto LAB_00446f95;
      iStack_24 = *(undefined4 *)(local_18 + 0x24);
      iStack_28 = local_c;
      uStack_2c = 0x446f7c;
      FUN_004cf170();
      iStack_28 = 0x446f86;
      cVar1 = FUN_00479720();
    } while (cVar1 == '\0');
    local_8 = local_c;
  }
LAB_00446f95:
  if (local_8 != *(int *)(local_18 + 0x15c)) {
    if (-1 < local_8) {
      iStack_24 = local_8;
      iStack_28 = 0x446fc0;
      iStack_24 = FUN_004cf170();
      iStack_28 = 0x446fcf;
      FUN_00479af0();
    }
    *(int *)(local_18 + 0x15c) = local_8;
    iStack_24 = 0x446fe3;
    FUN_00479ad0();
    if (*(int *)(local_18 + 0x15c) == -1) {
      *(undefined4 *)(local_18 + 0x40) = 0xffffffff;
      local_10 = abStack_3c;
      local_1c = basic_string<>(&DAT_007ce9f0);
      FUN_004787b0();
      *(undefined2 *)(local_18 + 0x58) = 0;
      *(undefined1 *)(local_18 + 0x53) = 1;
      *(undefined4 *)(local_18 + 0x1e8) = 0;
      iStack_24 = 0;
      iStack_28 = 0x447043;
      FUN_004cec60();
      iStack_24 = 0x447051;
      iVar3 = FUN_004d21f0();
      if (0 < iVar3) {
        iStack_24 = 0x447063;
        FUN_004d2300();
      }
    }
    else {
      *(undefined4 *)(local_18 + 0x40) = *(undefined4 *)(local_18 + 0x160);
      if (DAT_00a117d8 == 0) {
        local_14 = abStack_3c;
        local_20 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                   basic_string<char,std::char_traits<char>,std::allocator<char>_>
                             (abStack_3c,
                              (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                               *)(local_18 + 0x164));
        FUN_004787b0();
        iStack_24 = 0x4470b3;
        uVar2 = FUN_00479a10();
        *(undefined1 *)(local_18 + 0xac) = uVar2;
        iStack_24 = 0x4470ca;
        uVar2 = FUN_00479a30();
        *(undefined1 *)(local_18 + 0xad) = uVar2;
        *(ushort *)(local_18 + 0x44) = (ushort)*(byte *)(local_18 + 0x182);
        *(ushort *)(local_18 + 0x46) = (ushort)*(byte *)(local_18 + 0x183);
        *(ushort *)(local_18 + 0x58) = (ushort)*(byte *)(local_18 + 0x1ac);
        *(ushort *)(local_18 + 0x5a) = (ushort)*(byte *)(local_18 + 0x1ae);
        *(ushort *)(local_18 + 0x5e) = (ushort)*(byte *)(local_18 + 0x1af);
        *(ushort *)(local_18 + 0x5c) = (ushort)*(byte *)(local_18 + 0x1ad);
      }
      if (*(ushort *)(local_18 + 0x4e) != (ushort)*(byte *)(local_18 + 0x180)) {
        *(ushort *)(local_18 + 0x48) = (ushort)*(byte *)(local_18 + 0x180);
        *(undefined2 *)(local_18 + 0x4e) = *(undefined2 *)(local_18 + 0x48);
        *(undefined4 *)(local_18 + 0x74) = 0;
      }
      if (*(ushort *)(local_18 + 0x4c) != (ushort)*(byte *)(local_18 + 0x181)) {
        *(ushort *)(local_18 + 0x4a) = (ushort)*(byte *)(local_18 + 0x181);
        *(undefined2 *)(local_18 + 0x4c) = *(undefined2 *)(local_18 + 0x4a);
      }
      if (*(char *)(local_18 + 0x52) == '\0') {
        iStack_24 = local_18 + 0x1ac;
        iStack_28 = 0x447200;
        FUN_00473ea0();
        *(undefined2 *)(local_18 + 0xa8) = 0;
        *(undefined1 *)(local_18 + 0x52) = 0;
      }
      else {
        iStack_24 = local_18 + 0x1ac;
        iStack_28 = 0x4471d6;
        FUN_00473ea0();
        *(undefined2 *)(local_18 + 0xaa) = 0;
        *(undefined1 *)(local_18 + 0x52) = 1;
      }
      *(undefined4 *)(local_18 + 0x250) = 0xffffffff;
      *(undefined4 *)(local_18 + 0x254) = 0xffffffff;
      iStack_24 = 0x44723b;
      uVar2 = FUN_00479ab0();
      *(undefined1 *)(local_18 + 0xb9) = uVar2;
      iStack_24 = 0x447252;
      uVar2 = FUN_00479a50();
      *(undefined1 *)(local_18 + 0xae) = uVar2;
      iStack_24 = 0x447269;
      uVar2 = FUN_00479a70();
      *(undefined1 *)(local_18 + 0x53) = uVar2;
      iStack_24 = 0x44727d;
      uVar2 = FUN_00479a90();
      *(undefined1 *)(local_18 + 0xaf) = uVar2;
      *(uint *)(local_18 + 0x1e8) = (uint)*(byte *)(local_18 + 0x184);
      iStack_24 = local_18 + 0x1c8;
      iStack_28 = 0x4472b0;
      FUN_004cead0();
      iStack_24 = local_18 + 0x1d8;
      iStack_28 = 0x4472c8;
      FUN_004cd5b0();
      if (*DAT_00a16694 == '\x01') {
        *(undefined4 *)(local_18 + 0xb4) = 2;
      }
      else {
        *(undefined4 *)(local_18 + 0xb4) = 1;
      }
      iStack_24 = 0x447300;
      FUN_004d2300();
      if (*(int *)(local_18 + 0x1e8) == 2) {
        iStack_24 = 1;
        iStack_28 = 0x44731c;
        FUN_004d21c0();
        iStack_24 = 0;
        iStack_28 = 0;
        uStack_2c = 0;
        uStack_30 = 0x447330;
        FUN_004d2250();
        uStack_2c = 0x447337;
        FUN_0044ea60();
      }
      iStack_24 = 0x44733f;
      FUN_00479bd0();
    }
  }
  return;
}

