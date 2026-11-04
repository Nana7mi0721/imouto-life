
undefined4 FUN_005a6fe0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_58;
  int local_54;
  undefined1 local_50 [4];
  int local_4c;
  int local_48;
  int local_44;
  undefined1 local_40 [8];
  char local_38;
  char local_32;
  char local_31;
  char local_2c;
  char local_29;
  char local_1f;
  char local_1a;
  
  FUN_0059f390();
  DAT_00a37dc8 = 0;
  if (((DAT_00ddb5f8 != 0) && (DAT_00ddb5fc != 0)) || ((DAT_00ddb5f0 != 0 && (DAT_00ddb5f4 != 0))))
  {
    DAT_00a37dc8 = 1;
    iVar1 = FUN_00597a60();
    if (iVar1 == 0) {
      FUN_0056bca0(&DAT_007fc8d4);
      DAT_00a37dc8 = 0;
      FUN_0056bca0(&DAT_007fc8a8);
      goto LAB_005a73c9;
    }
    iVar1 = FUN_0056fda0(&DAT_00e8b650);
    iVar2 = FUN_00570e30(&DAT_00e8b650,0x7ffd,"Base2DVertexShader.vso",&local_58,local_50);
    if ((iVar2 == 0) && (iVar2 = FUN_005d3c10(local_58 + iVar1,&DAT_00e02d7c), iVar2 != 0)) {
      FUN_0056bca0(&DAT_007fc850);
      DAT_00a37dc8 = 0;
      FUN_0056bca0(&DAT_007fc8a8);
      goto LAB_005a73c9;
    }
    FUN_0056cf40(local_40,0x40,"ps_nonetex_type0_ach0.pso");
    local_54 = 0;
    do {
      local_31 = (char)local_54 + '0';
      iVar2 = 0;
      do {
        local_2c = (char)iVar2 + '0';
        iVar3 = FUN_00570e30(&DAT_00e8b650,0x7ffd,local_40,&local_58,local_50);
        if ((iVar3 == 0) &&
           (iVar3 = FUN_005d3d00(local_58 + iVar1,&DAT_00e02d80 + iVar2 + local_54 * 2), iVar3 != 0)
           ) goto LAB_005a72d4;
        iVar2 = iVar2 + 1;
      } while (iVar2 < 2);
      local_54 = local_54 + 1;
    } while (local_54 < 7);
    FUN_0056cf40(local_40,0x40,"ps_blend0_type0_igcolor0_igtalpha0_ach0.pso");
    local_54 = 0;
    iVar2 = 0;
    do {
      local_38 = (char)local_54 + '0';
      local_44 = 0;
      do {
        local_32 = (char)local_44 + '0';
        local_48 = 0;
        do {
          local_29 = (char)local_48 + '0';
          local_4c = 0;
          do {
            local_1f = (char)local_4c + '0';
            iVar3 = 0;
            do {
              local_1a = (char)iVar3 + '0';
              iVar4 = FUN_00570e30(&DAT_00e8b650,0x7ffd,local_40,&local_58,local_50);
              if ((iVar4 == 0) &&
                 (iVar4 = FUN_005d3d00(local_58 + iVar1,
                                       &DAT_00e02db8 +
                                       iVar3 + (local_4c + (local_48 + (iVar2 + local_44) * 2) * 2)
                                               * 2), iVar4 != 0)) goto LAB_005a72d4;
              iVar3 = iVar3 + 1;
            } while (iVar3 < 2);
            local_4c = local_4c + 1;
          } while (local_4c < 2);
          local_48 = local_48 + 1;
        } while (local_48 < 2);
        local_44 = local_44 + 1;
      } while (local_44 < 7);
      local_54 = local_54 + 1;
      iVar2 = iVar2 + 7;
    } while (iVar2 < 0x1c);
    FUN_00570e30(&DAT_00e8b650,0x7ffd,"ps_mask_blend.pso",&local_58,local_50);
    iVar2 = FUN_005d3d00(local_58 + iVar1,&DAT_00e03138);
    if (iVar2 != 0) {
      FUN_0056bca0(&DAT_007fc7b4);
      DAT_00a37dc8 = 0;
      FUN_0056bca0(&DAT_007fc8a8);
      goto LAB_005a73c9;
    }
    iVar2 = 0;
    do {
      FUN_00570e30(&DAT_00e8b650,0x7ffd,
                   *(undefined4 *)((int)&PTR_s_ps_mask_blend_use_grhandle_cha_p_0085fc10 + iVar2),
                   &local_58,local_50);
      iVar3 = FUN_005d3d00(local_58 + iVar1,(int)&DAT_00e0313c + iVar2);
      if (iVar3 != 0) {
LAB_005a7392:
        FUN_0056bca0(&DAT_007fc7b4);
        DAT_00a37dc8 = 0;
        FUN_0056bca0(&DAT_007fc8a8);
        goto LAB_005a73c9;
      }
      FUN_00570e30(&DAT_00e8b650,0x7ffd,
                   *(undefined4 *)((int)&PTR_s_ps_mask_blend_use_grhandle_cha_r_0085fc00 + iVar2),
                   &local_58,local_50);
      iVar3 = FUN_005d3d00(local_58 + iVar1,(int)&DAT_00e0314c + iVar2);
      if (iVar3 != 0) goto LAB_005a7392;
      iVar2 = iVar2 + 4;
    } while (iVar2 < 0x10);
    if (DAT_00a37dc8 != 0) {
      FUN_0056bca0(&DAT_007fc758);
      goto LAB_005a73c9;
    }
  }
  FUN_0056bca0(&DAT_007fc8a8);
LAB_005a73c9:
  FUN_0059cb80(&DAT_00ddb600,0,0,0,&DAT_0085fbf0,1,1);
  FUN_0059cb80(&DAT_00ddb600,3,0,0,&DAT_0085fbe0,1,1);
  return 1;
LAB_005a72d4:
  FUN_0056bca0(&DAT_007fc780);
  DAT_00a37dc8 = 0;
  FUN_0056bca0(&DAT_007fc8a8);
  goto LAB_005a73c9;
}

