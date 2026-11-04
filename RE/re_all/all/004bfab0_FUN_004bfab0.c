
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_004bfab0(undefined4 *param_1)

{
  ushort uVar1;
  bool bVar2;
  char cVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  char *pcVar6;
  undefined1 *puVar7;
  int *piVar8;
  undefined4 uVar9;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbVar10;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_f4 [16];
  undefined4 uStack_e4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_e0;
  undefined4 uStack_dc;
  uint uStack_d8;
  int *piStack_d4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_d0;
  char local_bc;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_98 [28];
  undefined1 *local_7c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_78 [31];
  char local_59;
  undefined1 *local_58;
  undefined1 *local_54;
  undefined1 *local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_3c [28];
  undefined4 local_20;
  int local_1c;
  int local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0b22;
  local_10 = ExceptionList;
  local_20 = DAT_0084b484;
  bVar2 = false;
  local_11 = '\0';
  ExceptionList = &local_10;
  if ((DAT_00a141f8 == '\0') &&
     (ExceptionList = &local_10, param_1[0xb] == *(int *)(param_1[4] + 0x40))) {
    pbStack_d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 (param_1[4] + 8);
    piStack_d4 = param_1 + 0x10;
    uStack_d8 = 0x4bfb29;
    ExceptionList = &local_10;
    cVar3 = operator!=<>();
    if ((cVar3 != '\0') || (param_1[0x1a] != (int)*(short *)(param_1[4] + 0x50))) goto LAB_004bfb4f;
  }
  else {
LAB_004bfb4f:
    param_1[0xb] = *(undefined4 *)(param_1[4] + 0x40);
    pbStack_d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 (param_1[4] + 8);
    piStack_d4 = (int *)0x4bfb7f;
    FUN_004cb840();
    if ((int)param_1[0xb] < 0) {
      local_11 = '\x01';
      param_1[0x1a] = 0;
      param_1[0x1b] = (int)*DAT_00a16690 << 1;
      pbStack_d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   &DAT_007d0621;
      piStack_d4 = (int *)(param_1[4] + 8);
      uStack_d8 = 0x4bfc79;
      cVar3 = operator!=<>();
      if (cVar3 == '\0') {
        *param_1 = 0xffffffff;
        param_1[3] = 0xffffffff;
      }
      else {
        param_1[0x1a] = (int)*(short *)(param_1[4] + 0x50);
        if (param_1[0x1a] == 1) {
          param_1[0x1b] = *DAT_00a16690 * 2 + 2;
        }
        if (param_1[0x1a] == 2) {
          param_1[0x1b] = (int)*DAT_00a16690 << 2;
        }
        if (*(char *)(param_1[4] + 0x55) == '\0') {
          param_1[0x1b] = (int)param_1[0x1b] / 2;
        }
        if (param_1[0x1a] == -1) {
          param_1[0x1b] = 1;
        }
        if ((int)param_1[0x1a] < 0) {
          pbStack_d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                       0x0;
          piStack_d4 = (int *)0x1;
          uStack_d8 = 1;
          local_58 = abStack_f4;
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
          basic_string<char,std::char_traits<char>,std::allocator<char>_>
                    (abStack_f4,
                     (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )(param_1[4] + 8));
          FUN_00422450();
          pbStack_d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                       (param_1[4] + 8);
          piStack_d4 = (int *)0x4bfeab;
          puVar4 = (undefined4 *)FUN_004cc680();
          *param_1 = *puVar4;
          pbStack_d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                       (param_1 + 0x19);
          piStack_d4 = param_1 + 0x18;
          uStack_d8 = 0;
          uStack_dc = *param_1;
          pbStack_e0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                       0x4bfede;
          FUN_004cde80();
          uStack_dc = 0x4bfee5;
          piVar8 = (int *)FUN_004ce990();
          uStack_d8 = *piVar8;
          uStack_dc = 0x4bfeed;
          FUN_00515880();
          param_1[0xc] = (int)param_1[0x18] / 2;
          param_1[0xd] = param_1[0x19];
        }
        else {
          pbStack_d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                       0x0;
          piStack_d4 = (int *)0x4;
          uStack_d8 = param_1[0x1b];
          local_54 = abStack_f4;
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
          basic_string<char,std::char_traits<char>,std::allocator<char>_>
                    (abStack_f4,
                     (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )(param_1[4] + 8));
          cVar3 = FUN_00422450();
          if (cVar3 == '\0') {
            *(undefined1 *)((int)param_1 + 0x5d) = 1;
            ExceptionList = local_10;
            return;
          }
          pbStack_d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                       (param_1[4] + 8);
          piStack_d4 = (int *)0x4bfd9d;
          puVar4 = (undefined4 *)FUN_004cc680();
          *param_1 = *puVar4;
          pbStack_d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                       (param_1 + 0x19);
          piStack_d4 = param_1 + 0x18;
          uStack_d8 = 0;
          uStack_dc = *param_1;
          pbStack_e0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                       0x4bfdd0;
          FUN_004cde80();
          uStack_dc = 0x4bfdd7;
          piVar8 = (int *)FUN_004ce990();
          uStack_d8 = *piVar8;
          uStack_dc = 0x4bfddf;
          FUN_00515880();
          local_18 = (int)param_1[0x18] / (int)param_1[0x1b];
          local_1c = (int)(param_1[0x19] + ((int)param_1[0x19] >> 0x1f & 3U)) >> 2;
          param_1[0xc] = local_18 / 2;
          param_1[0xd] = local_1c;
          param_1[0x18] = (int)param_1[0x18] / (int)param_1[0x1b];
          param_1[0x19] = (int)(param_1[0x19] + ((int)param_1[0x19] >> 0x1f & 3U)) >> 2;
        }
      }
    }
    else {
      pbStack_d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x1;
      piStack_d4 = (int *)DAT_0084b264;
      uStack_d8 = DAT_0084b264;
      local_50 = abStack_f4;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                (abStack_f4,
                 (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &DAT_00a17edc);
      FUN_00422450();
      pbStack_d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   &DAT_00a17edc;
      piStack_d4 = (int *)0x4bfbcd;
      puVar4 = (undefined4 *)FUN_004cc680();
      *param_1 = *puVar4;
      param_1[1] = param_1[0xb] + 1;
      param_1[0xc] = DAT_0084b264 / 2;
      param_1[0xd] = DAT_0084b264;
      param_1[0x18] = DAT_0084b264;
      param_1[0x19] = DAT_0084b264;
      param_1[0x1b] = 8;
    }
  }
  *(undefined4 *)(param_1[4] + 0xd8) = param_1[0x18];
  *(undefined4 *)(param_1[4] + 0xdc) = param_1[0x19];
  if (local_11 == '\0') {
    uVar1 = *(ushort *)(param_1[4] + 0xbc);
    pbStack_d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0;
    piStack_d4 = (int *)0x4bff92;
    pbVar5 = (byte *)FUN_004cd7c0();
    if (uVar1 == *pbVar5) {
      ExceptionList = local_10;
      return;
    }
    pbStack_d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 &DAT_007d0621;
    piStack_d4 = (int *)(param_1[4] + 8);
    uStack_d8 = 0x4bffb4;
    cVar3 = operator!=<>();
    if (cVar3 == '\0') {
      ExceptionList = local_10;
      return;
    }
  }
  pbStack_d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0;
  piStack_d4 = (int *)0x4bffd8;
  pbVar5 = (byte *)FUN_004cd7c0();
  *(ushort *)(param_1[4] + 0xbc) = (ushort)*pbVar5;
  param_1[0x1c] = (int)*DAT_00a16690 << 1;
  if (*(char *)(param_1[4] + 0x55) == '\0') {
    param_1[0x1c] = (int)param_1[0x1c] / 2;
  }
  pbStack_d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x4c002f
  ;
  basic_string<>();
  local_8 = 0;
  pbStack_d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0;
  piStack_d4 = (int *)0x4c004c;
  pcVar6 = (char *)FUN_004cd7c0();
  if ((*pcVar6 != -1) && (*DAT_00a16688 == '\x01')) {
    pbStack_d0 = local_3c;
    piStack_d4 = (int *)0x0;
    uStack_d8 = 0;
    uStack_dc = 0x4c0084;
    pbVar5 = (byte *)FUN_004cd7c0();
    uStack_d8 = (uint)*pbVar5;
    uStack_dc = 9;
    pbStack_e0 = local_78;
    uStack_e4 = 0x4c0098;
    piStack_d4 = (int *)FUN_0046ff30();
    local_8 = CONCAT31(local_8._1_3_,1);
    bVar2 = true;
    pbStack_d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 &DAT_007d0621;
    uStack_d8 = 0x4c00ce;
    cVar3 = operator!=<>();
    if (cVar3 != '\0') {
      local_bc = '\x01';
      goto LAB_004c00ee;
    }
  }
  local_bc = '\0';
LAB_004c00ee:
  local_59 = local_bc;
  local_8 = 0;
  if (bVar2) {
    pbStack_d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 0x4c0118;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_78);
  }
  if (local_59 == '\0') {
    param_1[3] = 0xffffffff;
  }
  else {
    pbStack_d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0;
    piStack_d4 = (int *)0x4;
    uStack_d8 = param_1[0x1c];
    local_7c = abStack_f4;
    pbVar10 = local_3c;
    uVar9 = 0;
    puVar7 = (undefined1 *)FUN_004cd7c0(0);
    FUN_0046ff30(abStack_f4,9,*puVar7,uVar9,pbVar10);
    FUN_00422450();
    pbStack_d0 = local_3c;
    piStack_d4 = (int *)0x0;
    uStack_d8 = 0;
    uStack_dc = 0x4c0191;
    pbVar5 = (byte *)FUN_004cd7c0();
    uStack_d8 = (uint)*pbVar5;
    uStack_dc = 9;
    pbStack_e0 = local_98;
    uStack_e4 = 0x4c01a8;
    pbStack_d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 FUN_0046ff30();
    local_8._0_1_ = 2;
    piStack_d4 = (int *)0x4c01cf;
    puVar4 = (undefined4 *)FUN_004cc680();
    param_1[3] = *puVar4;
    local_8 = (uint)local_8._1_3_ << 8;
    pbStack_d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 0x4c01e9;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_98);
    pbStack_d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 &local_44;
    piStack_d4 = &local_48;
    uStack_d8 = 0;
    uStack_dc = param_1[3];
    pbStack_e0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 0x4c0207;
    FUN_004cde80();
    uStack_dc = 0x4c020e;
    piVar8 = (int *)FUN_004ce990();
    uStack_d8 = *piVar8;
    uStack_dc = 0x4c0216;
    FUN_00515880();
    local_40 = local_48 / (int)param_1[0x1c];
    local_4c = (int)(local_44 + (local_44 >> 0x1f & 3U)) >> 2;
    param_1[0xe] = local_40 / 2;
    param_1[0xf] = local_4c;
  }
  local_8 = 0xffffffff;
  pbStack_d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x4c0273
  ;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_3c);
  ExceptionList = local_10;
  return;
}

