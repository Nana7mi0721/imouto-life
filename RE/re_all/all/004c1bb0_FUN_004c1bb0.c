
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004c1bb0(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  float10 fVar4;
  longlong lVar5;
  int iStack_138;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_120;
  undefined *puStack_11c;
  int *piStack_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  int local_d4;
  undefined1 *local_d0;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_bc [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_a0 [28];
  undefined1 *local_84;
  undefined1 *local_80;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_7c [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_60 [28];
  undefined1 *local_44;
  undefined1 *local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  longlong local_30;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0d11;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_d4 = param_1;
  if (DAT_00a17eb8 == -1) {
    piStack_118 = (int *)0x4c1be8;
    ExceptionList = &local_10;
    FUN_004cb470();
  }
  if (DAT_00a13fa0 != -1) {
    if (DAT_00a140a9 != '\0') {
      DAT_00a14314 = 0;
      DAT_00a18ad0 = 0xffffffff;
      piStack_118 = (int *)0x4c1c24;
      FUN_004c1ae0();
      piStack_118 = (int *)0x4c1c29;
      FUN_00423060();
      piStack_118 = (int *)0x4c1c34;
      FUN_004c0d40();
      piStack_118 = (int *)0x4c1c45;
      FUN_00476570();
      piStack_118 = (int *)0x4c1c56;
      FUN_004c1a20();
      piStack_118 = (int *)0x4c1c67;
      FUN_00476390();
      iVar3 = DAT_00a18a34;
      DAT_00a140a9 = '\0';
      DAT_00a117ae = '\0';
      local_18 = DAT_00a18a34;
      local_14 = DAT_00a18a38;
      DAT_00a18a34 = -100;
      DAT_00a18a38 = -100;
      if ((iVar3 == -3) || (DAT_00a14328 <= iVar3)) {
        piStack_118 = (int *)&DAT_007d0621;
        puStack_11c = &DAT_00a18b94;
        pbStack_120 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x4c1ccb;
        cVar1 = operator!=<>();
        if (cVar1 == '\0') {
          local_18 = -1;
        }
        else {
          local_18 = DAT_00a14328;
          local_40 = (undefined1 *)&uStack_130;
          iStack_138 = 0x4c1cf3;
          local_d8 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                     basic_string<char,std::char_traits<char>,std::allocator<char>_>
                               ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                                &uStack_130,
                                (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                                 *)&DAT_00a18b94);
          iStack_138 = local_18;
          FUN_00478010(1);
          piStack_118 = (int *)DAT_00a18bcc;
          puStack_11c = (undefined *)0x1;
          pbStack_120 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )local_18;
          uStack_124 = 1;
          uStack_128 = 0x4c1d24;
          FUN_00477f90();
          piStack_118 = (int *)DAT_00a18bd0;
          puStack_11c = (undefined *)0x2;
          pbStack_120 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )local_18;
          uStack_124 = 1;
          uStack_128 = 0x4c1d3d;
          FUN_00477f90();
          piStack_118 = (int *)DAT_00a18bd4;
          puStack_11c = (undefined *)0x3;
          pbStack_120 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )local_18;
          uStack_124 = 1;
          uStack_128 = 0x4c1d55;
          FUN_00477f90();
          piStack_118 = (int *)local_18;
          puStack_11c = (undefined *)0x0;
          local_44 = (undefined1 *)&iStack_138;
          local_dc = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                     basic_string<char,std::char_traits<char>,std::allocator<char>_>
                               ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                                &iStack_138,
                                (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                                 *)&DAT_00a18b94);
          FUN_0047df80();
          piStack_118 = (int *)0x4c1d87;
          piStack_118 = (int *)FUN_004cbb30();
          puStack_11c = (undefined *)0x4c1d90;
          puStack_11c = (undefined *)basic_string<>();
          local_8 = 0;
          piStack_118 = (int *)&DAT_00a18b94;
          pbStack_120 = local_7c;
          uStack_124 = 0x4c1dbe;
          local_e4 = puStack_11c;
          local_e0 = puStack_11c;
          piStack_118 = (int *)FUN_004ec790();
          local_8._0_1_ = 1;
          puStack_11c = (undefined *)0x4c1de8;
          local_ec = piStack_118;
          local_e8 = piStack_118;
          puVar2 = (undefined4 *)FUN_004cc680();
          local_1c = *puVar2;
          local_8 = (uint)local_8._1_3_ << 8;
          piStack_118 = (int *)0x4c1df9;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_7c);
          local_8 = 0xffffffff;
          piStack_118 = (int *)0x4c1e08;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_60);
          piStack_118 = &local_18;
          puStack_11c = (undefined *)0x4c1e16;
          puVar2 = (undefined4 *)FUN_004cc020();
          *puVar2 = local_1c;
          DAT_00a14334 = DAT_00a14334 + 1;
        }
      }
      if ((local_14 == -3) || (DAT_00a1432c <= local_18)) {
        piStack_118 = (int *)&DAT_007d0621;
        puStack_11c = &DAT_00a18bb0;
        pbStack_120 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x4c1e57;
        cVar1 = operator!=<>();
        if (cVar1 == '\0') {
          local_14 = -1;
        }
        else {
          local_14 = DAT_00a1432c;
          local_80 = (undefined1 *)&uStack_130;
          iStack_138 = 0x4c1e80;
          local_f0 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                     basic_string<char,std::char_traits<char>,std::allocator<char>_>
                               ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                                &uStack_130,
                                (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                                 *)&DAT_00a18bb0);
          iStack_138 = local_14;
          FUN_00478010(2);
          piStack_118 = (int *)DAT_00a18bd8;
          puStack_11c = (undefined *)0x1;
          pbStack_120 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )local_14;
          uStack_124 = 2;
          uStack_128 = 0x4c1eb1;
          FUN_00477f90();
          piStack_118 = (int *)DAT_00a18bdc;
          puStack_11c = (undefined *)0x2;
          pbStack_120 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )local_14;
          uStack_124 = 2;
          uStack_128 = 0x4c1ec9;
          FUN_00477f90();
          piStack_118 = (int *)DAT_00a18be0;
          puStack_11c = (undefined *)0x3;
          pbStack_120 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )local_14;
          uStack_124 = 2;
          uStack_128 = 0x4c1ee2;
          FUN_00477f90();
          piStack_118 = (int *)local_14;
          puStack_11c = (undefined *)0x0;
          local_84 = (undefined1 *)&iStack_138;
          local_f4 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                     basic_string<char,std::char_traits<char>,std::allocator<char>_>
                               ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                                &iStack_138,
                                (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                                 *)&DAT_00a18bb0);
          FUN_0047df80();
          piStack_118 = (int *)0x4c1f14;
          piStack_118 = (int *)FUN_004cbb30();
          puStack_11c = (undefined *)0x4c1f20;
          puStack_11c = (undefined *)basic_string<>();
          local_8 = 2;
          piStack_118 = (int *)&DAT_00a18bb0;
          pbStack_120 = local_bc;
          uStack_124 = 0x4c1f51;
          local_fc = puStack_11c;
          local_f8 = puStack_11c;
          piStack_118 = (int *)FUN_004ec790();
          local_8._0_1_ = 3;
          puStack_11c = (undefined *)0x4c1f7b;
          local_104 = piStack_118;
          local_100 = piStack_118;
          puVar2 = (undefined4 *)FUN_004cc680();
          local_20 = *puVar2;
          local_8 = CONCAT31(local_8._1_3_,2);
          piStack_118 = (int *)0x4c1f8f;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_bc);
          local_8 = 0xffffffff;
          piStack_118 = (int *)0x4c1fa1;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_a0);
          piStack_118 = &local_14;
          puStack_11c = (undefined *)0x4c1faf;
          puVar2 = (undefined4 *)FUN_004cc020();
          *puVar2 = local_20;
          DAT_00a14338 = DAT_00a14338 + 1;
        }
      }
      piStack_118 = (int *)0x0;
      puStack_11c = (undefined *)0x14;
      pbStack_120 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    local_18;
      uStack_124 = 0;
      uStack_128 = 0x4c1fe0;
      FUN_0047a5d0();
      piStack_118 = (int *)0x0;
      puStack_11c = (undefined *)0x14;
      pbStack_120 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    local_14;
      uStack_124 = 1;
      uStack_128 = 0x4c1ff4;
      FUN_0047a5d0();
      _DAT_00a16540 = &DAT_00a143d8;
      _DAT_00a16544 = &DAT_00a14bb8;
      _DAT_00a16548 = &DAT_00a16538;
      piStack_118 = (int *)0x4c201d;
      piStack_118 = (int *)FUN_00471820();
      local_8 = 4;
      puStack_11c = (undefined *)0x4c2047;
      local_10c = piStack_118;
      local_108 = piStack_118;
      FUN_00473710();
      local_8 = 0xffffffff;
      piStack_118 = (int *)0x4c2059;
      FUN_0047a000();
      local_d0 = (undefined1 *)&uStack_130;
      iStack_138 = 0x4c206e;
      local_110 = basic_string<>();
      FUN_0047ecc0();
      FUN_00436d00();
      piStack_118 = (int *)0x1;
      puStack_11c = (undefined *)0x0;
      pbStack_120 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x4c2096;
      FUN_0044ea60();
      DAT_00a117d8 = 1;
      piStack_118 = (int *)0x4c20aa;
      FUN_0044b650();
      DAT_00a117d8 = 0;
    }
    DAT_00a18b4c = (DAT_00a18b4c + 1) % 10000000;
    if (DAT_00a140cc != '\0') {
      DAT_00a140cc = '\0';
      piStack_118 = (int *)0x4c20fa;
      FUN_004c03f0();
    }
    piStack_118 = (int *)0x4c2104;
    FUN_0044b650();
    piStack_118 = (int *)0x4c210e;
    FUN_0044ef40();
    local_24 = 0;
    while( true ) {
      piStack_118 = (int *)0x4c212a;
      iVar3 = FUN_004d2d60();
      if (iVar3 <= local_24) break;
      piStack_118 = (int *)local_24;
      puStack_11c = (undefined *)0x4c213d;
      FUN_004d2dc0();
      piStack_118 = (int *)0x4c2144;
      FUN_004c2510();
      local_24 = local_24 + 1;
    }
    if (((DAT_00a117ae == '\0') && (DAT_00a140a9 == '\0')) && (DAT_00a13fa0 != -1)) {
      piStack_118 = (int *)0x4c2174;
      FUN_00445a90();
      if (DAT_00a14061 != '\0') {
        piStack_118 = (int *)0x4c218a;
        FUN_004cb470();
      }
      piStack_118 = (int *)0x4c219b;
      FUN_004c35c0();
      piStack_118 = (int *)0x4c21ac;
      FUN_004c2ae0();
      piStack_118 = (int *)0x4c21b6;
      FUN_004c4b90();
      piStack_118 = (int *)0x4c21c0;
      FUN_004bb030();
      piStack_118 = (int *)0x4c21ca;
      FUN_004c2a80();
      piStack_118 = (int *)0x4c21d4;
      FUN_004c27a0();
      piStack_118 = (int *)0x4c21df;
      FUN_004cb440();
      piStack_118 = (int *)0x4c21e9;
      FUN_004c5fa0();
      piStack_118 = (int *)0x0;
      puStack_11c = (undefined *)0x4c21f0;
      iVar3 = FUN_00550060();
      _DAT_00a140d0 = iVar3 - _DAT_00a140d0;
      *(int *)(local_d4 + 0x9f38) = (int)(DAT_00a17ebc + (DAT_00a17ebc >> 0x1f & 3U)) >> 2;
      *(int *)(local_d4 + 0x9f3c) = (int)(DAT_00a17ec0 + (DAT_00a17ec0 >> 0x1f & 3U)) >> 2;
      if (DAT_00a141f8 != '\0') {
        local_28 = 0;
        while( true ) {
          piStack_118 = (int *)0x4c2259;
          iVar3 = FUN_004d29a0();
          if (iVar3 <= local_28) break;
          piStack_118 = (int *)local_28;
          puStack_11c = (undefined *)0x4c2273;
          FUN_004d3c00();
          piStack_118 = (int *)0x4c227a;
          FUN_004bfab0();
          local_28 = local_28 + 1;
        }
      }
      if (((*(char *)(local_d4 + 0xa468) != '\0') &&
          ((float)_DAT_00802e18 <= *(float *)(local_d4 + 0xa46c))) && (DAT_00a14092 == '\0')) {
        piStack_118 = (int *)0x0;
        puStack_11c = (undefined *)0x4c22c4;
        local_34 = FUN_00550060();
        piStack_118 = (int *)0x0;
        puStack_11c = (undefined *)0x4c22d1;
        local_30 = FUN_00550090();
        piStack_118 = (int *)0x0;
        puStack_11c = (undefined *)0x4c22e1;
        FUN_005165c0();
        *(undefined4 *)(local_d4 + 0xa46c) = 0;
        piStack_118 = (int *)0x0;
        puStack_11c = (undefined *)0x4c22fb;
        FUN_005160a0();
        if (DAT_00a140a8 == '\0') {
          piStack_118 = (int *)0x0;
          puStack_11c = (undefined *)0x0;
          pbStack_120 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x0;
          uStack_124 = 0x4c231d;
          FUN_004bf5b0();
          if (DAT_00a18aca == '\0') {
            piStack_118 = (int *)0x4c2349;
            FUN_004c2a40();
          }
          else {
            piStack_118 = (int *)0x4c2333;
            FUN_004c61a0();
          }
          local_114 = 0;
          piStack_118 = (int *)0x0;
          puStack_11c = (undefined *)0x0;
          pbStack_120 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x1;
          uStack_124 = 0x4c2363;
          FUN_004bf5b0();
          piStack_118 = (int *)0x0;
          puStack_11c = (undefined *)0x1;
          pbStack_120 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x0;
          uStack_124 = 0x4c2373;
          FUN_004bf5b0();
          piStack_118 = (int *)DAT_00a117d0;
          puStack_11c = (undefined *)0x4c237e;
          FUN_005160a0();
          piStack_118 = (int *)0xff;
          puStack_11c = (undefined *)0x2;
          pbStack_120 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x4c238d;
          FUN_005160d0();
          piStack_118 = (int *)0x1;
          puStack_11c = (undefined *)0x0;
          pbStack_120 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x1;
          uStack_124 = 1;
          uStack_128 = 0;
          uStack_12c = 0;
          uStack_130 = 0x4c23a1;
          FUN_00526390();
          piStack_118 = (int *)0xff;
          puStack_11c = (undefined *)0x0;
          pbStack_120 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x4c23b0;
          FUN_005160d0();
          piStack_118 = (int *)0x0;
          puStack_11c = (undefined *)0x4c23bf;
          FUN_004c5e60();
          piStack_118 = (int *)0xff;
          puStack_11c = (undefined *)0xff;
          pbStack_120 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0xff;
          uStack_124 = 0x4c23d3;
          FUN_005161e0();
          piStack_118 = (int *)0x4c23e7;
          FUN_004c2f90();
          piStack_118 = (int *)0x4c23f8;
          FUN_004c40f0();
          piStack_118 = (int *)0x1;
          puStack_11c = (undefined *)0x4c2404;
          FUN_004c5e60();
          piStack_118 = (int *)0x0;
          puStack_11c = (undefined *)0x4c240b;
          FUN_005160a0();
          piStack_118 = (int *)0x4c2418;
          FUN_004c25f0();
          piStack_118 = (int *)0x4c2422;
          FUN_004c28d0();
          piStack_118 = (int *)0x4c242c;
          FUN_00467d60();
          local_38 = 0;
          while( true ) {
            piStack_118 = (int *)0x4c2448;
            iVar3 = FUN_004d29a0();
            if (iVar3 <= local_38) break;
            piStack_118 = (int *)local_38;
            puStack_11c = (undefined *)0x4c245b;
            FUN_004d2a00();
            piStack_118 = (int *)0x4c2462;
            FUN_004c6160();
            local_38 = local_38 + 1;
          }
          local_3c = 0;
          while( true ) {
            piStack_118 = (int *)0x4c2480;
            iVar3 = FUN_004d2d60();
            if (iVar3 <= local_3c) break;
            piStack_118 = (int *)local_3c;
            puStack_11c = (undefined *)0x4c2493;
            FUN_004d2dc0();
            piStack_118 = (int *)0x4c249a;
            FUN_004c25b0();
            local_3c = local_3c + 1;
          }
        }
        else {
          piStack_118 = (int *)0x4c24a8;
          FUN_004c28d0();
        }
        piStack_118 = (int *)0x4c24b2;
        fVar4 = (float10)FUN_004bd490();
        piStack_118 = (int *)(float)fVar4;
        puStack_11c = (undefined *)0x4c24bb;
        FUN_00434720();
        if (DAT_00a11798 != 0) {
          piStack_118 = (int *)0x4c24cc;
          FUN_004177c0();
        }
        piStack_118 = (int *)0x0;
        puStack_11c = (undefined *)0x4c24d3;
        lVar5 = FUN_00550090();
        DAT_00a140e8 = (undefined4)(lVar5 - local_30);
        DAT_00a140ec = (undefined4)((ulonglong)(lVar5 - local_30) >> 0x20);
        piStack_118 = (int *)0x4c24ec;
        thunk_FUN_00522bc0();
        DAT_00a141f8 = '\0';
      }
    }
  }
  ExceptionList = local_10;
  return;
}

