
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_0044be30(int param_1)

{
  short sVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined2 *puVar6;
  undefined2 local_c0;
  undefined2 local_bc;
  int local_b8;
  int local_70;
  int local_6c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_60 [28];
  byte local_44;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ad813;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  ExceptionList = &local_10;
  cVar2 = FUN_00478410();
  if ((cVar2 == '\0') && (cVar2 = FUN_004780e0(), cVar2 == '\0')) {
    FUN_00484e90();
    local_8 = 0;
    while (sVar1 = *(short *)(param_1 + 0xa8), iVar3 = FUN_004ce5c0(), sVar1 <= iVar3) {
      if (0 < *(int *)(param_1 + 0x70)) {
        local_8 = 0xffffffff;
        FUN_004864a0();
        ExceptionList = local_10;
        return;
      }
      sVar1 = *(short *)(param_1 + 0xa8);
      iVar3 = FUN_004ce5c0();
      if (sVar1 == iVar3) {
        if ((*(byte *)(param_1 + 0x7d) & 1) != 0) {
          *(undefined2 *)(param_1 + 0xa8) = 0;
        }
        if ((*(byte *)(param_1 + 0x7d) & 1) == 0) {
          if (*(char *)(param_1 + 0x52) != '\0') {
            *(undefined1 *)(param_1 + 0x52) = 0;
            FUN_00473ea0();
            *(undefined2 *)(param_1 + 0xa8) = *(undefined2 *)(param_1 + 0xaa);
            FUN_004ce590();
          }
          *(undefined4 *)(param_1 + 100) = 0;
        }
        local_8 = 0xffffffff;
        FUN_004864a0();
        ExceptionList = local_10;
        return;
      }
      iVar3 = FUN_004ce5c0();
      if (iVar3 == 0) {
        *(undefined1 *)(param_1 + 0x52) = 0;
      }
      FUN_004ce620();
      FUN_004864f0();
      for (local_6c = 0; iVar3 = FUN_004ce080(), local_6c < iVar3; local_6c = local_6c + 1) {
        piVar4 = (int *)FUN_004ce990();
        local_70 = *piVar4;
        if ((1099999 < local_70) && (local_70 < 1200000)) {
          local_70 = *(int *)(param_1 + 0x24) * 10 + 1000000 + local_70 % 10;
        }
        if ((1599999 < local_70) && (local_70 < 1700000)) {
          basic_string<>();
          local_8._0_1_ = 1;
          FUN_00438b60();
          local_8._0_1_ = 2;
          basic_string<>(&DAT_007ceb64);
          uVar5 = FUN_00401c50();
          basic_string<>(uVar5);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0042bed0();
          local_70 = 0;
        }
        piVar4 = (int *)FUN_004ce990();
        *piVar4 = local_70;
      }
      if ((local_44 < 8) ||
         ((((0xf < local_44 && (local_44 < 0x16)) || (local_44 == 0x35)) || (local_44 == 0x36)))) {
        switch(local_44) {
        case 0:
          FUN_004860a0();
          break;
        case 1:
          FUN_00486120();
          break;
        case 2:
          FUN_004861a0();
          break;
        case 3:
          FUN_00486220();
          break;
        case 4:
          FUN_004862a0();
          break;
        case 5:
          FUN_00486320();
          break;
        case 6:
          FUN_004863a0();
          break;
        case 7:
          FUN_00486420();
          break;
        case 0x10:
          FUN_0044e2e0();
          break;
        case 0x11:
          FUN_0044e420();
          break;
        case 0x12:
          FUN_00485530();
          break;
        case 0x13:
          FUN_00486b30();
          break;
        case 0x14:
          FUN_00485a70();
          break;
        case 0x15:
          FUN_004ce990();
          FUN_004ce990();
          FUN_0043b320();
          FUN_0043b320();
          FUN_00485b50();
          break;
        case 0x35:
          FUN_004ce990();
          FUN_0043b320();
          FUN_00484ef0();
          break;
        case 0x36:
          FUN_004ce990();
          FUN_004ce990();
          FUN_0043b320();
          FUN_0043b320();
          FUN_00484ef0();
        }
        if ((((*(byte *)(param_1 + 0x7d) & 2) == 0) && (cVar2 = FUN_004780e0(), cVar2 == '\0')) &&
           (cVar2 = FUN_00478410(), cVar2 == '\0')) {
          local_8 = 0xffffffff;
          FUN_004864a0();
          ExceptionList = local_10;
          return;
        }
        *(short *)(param_1 + 0xa8) = *(short *)(param_1 + 0xa8) + 1;
        local_8 = 0xffffffff;
        FUN_004864a0();
        ExceptionList = local_10;
        return;
      }
      if (((0x15 < local_44) && (local_44 < 0x1c)) || ((7 < local_44 && (local_44 < 0x10)))) {
        switch(local_44) {
        case 8:
          FUN_004784f0();
          break;
        case 9:
          FUN_004785a0();
          break;
        case 10:
          FUN_00478650();
          break;
        case 0xb:
          FUN_00478700();
          break;
        case 0xc:
          FUN_00478520();
          break;
        case 0xd:
          FUN_00478730();
          break;
        case 0xe:
          FUN_004785d0();
          break;
        case 0xf:
          FUN_00478680();
          break;
        case 0x16:
          FUN_00485d00();
          break;
        case 0x17:
          FUN_00485e20();
          break;
        case 0x18:
          FUN_00485f40();
          break;
        case 0x19:
          FUN_00485f80();
          break;
        case 0x1a:
          FUN_00443b30();
          break;
        case 0x1b:
          FUN_00443e40();
        }
        *(short *)(param_1 + 0xa8) = *(short *)(param_1 + 0xa8) + 1;
        local_8 = 0xffffffff;
        FUN_004864a0();
        ExceptionList = local_10;
        return;
      }
      basic_string<>();
      local_8._0_1_ = 3;
      if (0x1b < local_44) {
        switch(local_44) {
        case 0x1c:
          FUN_004ce990();
          FUN_004ce990();
          FUN_0043b320();
          FUN_00438f70();
          DAT_00a1809c = 1;
          break;
        case 0x1d:
          puVar6 = (undefined2 *)FUN_004ce990();
          *(undefined2 *)(param_1 + 0x5a) = *puVar6;
          break;
        case 0x1e:
          puVar6 = (undefined2 *)FUN_004ce990();
          *(undefined2 *)(param_1 + 0x5e) = *puVar6;
          break;
        case 0x1f:
          puVar6 = (undefined2 *)FUN_004ce990();
          *(undefined2 *)(param_1 + 0x5c) = *puVar6;
          break;
        case 0x20:
          *(undefined1 *)(param_1 + 0xad) = 1;
          break;
        case 0x21:
          *(undefined1 *)(param_1 + 0xad) = 0;
          break;
        case 0x22:
          *(undefined1 *)(param_1 + 0xac) = 1;
          break;
        case 0x23:
          *(undefined1 *)(param_1 + 0xac) = 0;
          break;
        case 0x24:
          *(undefined1 *)(param_1 + 0xae) = 1;
          break;
        case 0x25:
          *(undefined1 *)(param_1 + 0xae) = 0;
          break;
        case 0x26:
          *(undefined1 *)(param_1 + 0x53) = 1;
          break;
        case 0x27:
          *(undefined1 *)(param_1 + 0x53) = 0;
          break;
        case 0x28:
          *(undefined1 *)(param_1 + 0xaf) = 1;
          break;
        case 0x29:
          *(undefined1 *)(param_1 + 0xaf) = 0;
          break;
        case 0x2c:
          FUN_004ce990();
          FUN_0043b320();
          FUN_0046ff30();
          FUN_004787b0();
          break;
        case 0x2d:
          FUN_004ce990();
          iVar3 = FUN_0043b320();
          if (iVar3 < 0) {
            local_b8 = 0;
          }
          else {
            local_b8 = FUN_0043b320();
          }
          if (local_b8 < 0x100) {
            iVar3 = FUN_0043b320();
            if (iVar3 < 0) {
              local_c0 = 0;
            }
            else {
              local_c0 = FUN_0043b320();
            }
            local_bc = local_c0;
          }
          else {
            local_bc = 0xff;
          }
          *(undefined2 *)(param_1 + 0x44) = local_bc;
          break;
        case 0x2e:
          FUN_004ce990();
          FUN_0043b320();
          FUN_0047a5d0();
          break;
        case 0x2f:
          FUN_004ce990();
          uVar5 = FUN_0043b320();
          *(undefined4 *)(param_1 + 0x70) = uVar5;
          break;
        case 0x30:
          *(undefined4 *)(param_1 + 0xb4) = 1;
          break;
        case 0x31:
          *(undefined4 *)(param_1 + 0xb4) = 2;
          break;
        case 0x32:
          *(undefined2 *)(param_1 + 0x4c) = 0;
          break;
        case 0x33:
          *(undefined2 *)(param_1 + 0x4c) = 1;
          break;
        case 0x34:
          *(undefined2 *)(param_1 + 0x4c) = 2;
          break;
        case 0x37:
          FUN_004ce990();
          FUN_0043b320();
          FUN_004ce990();
          FUN_0043b320();
          FUN_00438f70();
          DAT_00a1809c = 1;
          break;
        case 0x38:
          *(undefined2 *)(param_1 + 0x4c) = 3;
          break;
        case 0x39:
          *(undefined2 *)(param_1 + 0x4c) = 4;
          break;
        case 0x3a:
          FUN_004ce990();
          uVar5 = FUN_0043b320();
          *(undefined4 *)(param_1 + 0xc4) = uVar5;
        }
        *(short *)(param_1 + 0xa8) = *(short *)(param_1 + 0xa8) + 1;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_60);
    }
    local_8 = 0xffffffff;
    FUN_004864a0();
  }
  ExceptionList = local_10;
  return;
}

