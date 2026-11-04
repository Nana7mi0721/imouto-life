
/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_0065ac70(uint param_1,uint param_2,int param_3,undefined4 *param_4)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  undefined4 *puVar4;
  undefined2 *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  int iVar11;
  uint *puVar12;
  undefined2 uVar13;
  undefined2 extraout_var_01;
  uint uVar14;
  short *psVar15;
  uint *puVar16;
  short *psVar17;
  char *pcVar18;
  longlong lVar19;
  undefined8 uVar20;
  undefined4 uVar21;
  uint local_24;
  uint uStack_20;
  undefined4 uStack_1c;
  uint uStack_18;
  char *pcStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar9 = param_1;
  psVar17 = (short *)0x0;
  if (*(int *)(param_1 + 8) == 0) {
    return 1;
  }
  FUN_0065f680();
  if (param_3 != 0) {
    if ((*(uint *)(iVar9 + 0xc) & 0x1000) != 0) {
      *(uint *)(iVar9 + 0xc) = *(uint *)(iVar9 + 0xc) & 0xffffefff;
      iVar10 = (**(code **)(iVar9 + 0x210))();
      if (iVar10 == 0) {
        FUN_006512e0(*(undefined4 *)(iVar9 + 0x274),"TIFFWriteDirectorySec",
                     s_Error_post_encoding_before_direc_00a0a6e8);
        return 0;
      }
    }
    (**(code **)(iVar9 + 0x22c))();
    if (((0 < *(int *)(iVar9 + 0x260)) && ((*(byte *)(iVar9 + 0xc) & 0x40) != 0)) &&
       (iVar10 = FUN_0065e6b0(), iVar10 == 0)) {
      FUN_006512e0(*(undefined4 *)(iVar9 + 0x274),"TIFFWriteDirectorySec",
                   s_Error_flushing_data_before_direc_00a0a6bc);
      return 0;
    }
    if (((*(uint *)(iVar9 + 0xc) & 0x200) != 0) && (*(int *)(iVar9 + 0x24c) != 0)) {
      FUN_006507e0();
      *(undefined4 *)(iVar9 + 0x24c) = 0;
      *(undefined4 *)(iVar9 + 0x260) = 0;
      *(undefined4 *)(iVar9 + 0x250) = 0;
      *(undefined4 *)(iVar9 + 0x254) = 0;
      *(undefined4 *)(iVar9 + 600) = 0;
    }
    *(uint *)(iVar9 + 0xc) = *(uint *)(iVar9 + 0xc) & 0xffffffaf;
  }
  local_24 = 0;
  do {
    param_1 = 0;
    if (param_2 != 0) {
      if (((((((*(byte *)(iVar9 + 0x28) & 2) != 0) &&
             ((iVar10 = FUN_0065c540(iVar9,&param_1,psVar17,0x100,*(undefined4 *)(iVar9 + 0x38)),
              iVar10 == 0 ||
              (iVar10 = FUN_0065c540(iVar9,&param_1,psVar17,0x101,*(undefined4 *)(iVar9 + 0x3c)),
              iVar10 == 0)))) ||
            (((*(byte *)(iVar9 + 0x28) & 4) != 0 &&
             ((iVar10 = FUN_0065c540(iVar9,&param_1,psVar17,0x142,*(undefined4 *)(iVar9 + 0x44)),
              iVar10 == 0 ||
              (iVar10 = FUN_0065c540(iVar9,&param_1,psVar17,0x143,*(undefined4 *)(iVar9 + 0x48)),
              iVar10 == 0)))))) ||
           (((*(byte *)(iVar9 + 0x28) & 8) != 0 &&
            ((iVar10 = FUN_0065c3c0(iVar9,&param_1,psVar17,0x11a,(double)*(float *)(iVar9 + 0x74)),
             iVar10 == 0 ||
             (iVar10 = FUN_0065c3c0(iVar9,&param_1,psVar17,0x11b,(double)*(float *)(iVar9 + 0x78)),
             iVar10 == 0)))))) ||
          ((((*(byte *)(iVar9 + 0x28) & 0x10) != 0 &&
            ((iVar10 = FUN_0065c3c0(iVar9,&param_1,psVar17,0x11e,(double)*(float *)(iVar9 + 0x80)),
             iVar10 == 0 ||
             (iVar10 = FUN_0065c3c0(iVar9,&param_1,psVar17,0x11f,(double)*(float *)(iVar9 + 0x84)),
             iVar10 == 0)))) ||
           ((((((*(byte *)(iVar9 + 0x28) & 0x20) != 0 &&
               (iVar10 = FUN_0065c280(iVar9,&param_1,psVar17,0xfe), iVar10 == 0)) ||
              (((*(byte *)(iVar9 + 0x28) & 0x40) != 0 &&
               (iVar10 = FUN_0065c1a0(iVar9,&param_1,psVar17,0x102), iVar10 == 0)))) ||
             (((*(byte *)(iVar9 + 0x28) & 0x80) != 0 &&
              (iVar10 = FUN_0065c120(iVar9,&param_1,psVar17,0x103), iVar10 == 0)))) ||
            (((((*(uint *)(iVar9 + 0x28) & 0x100) != 0 &&
               (iVar10 = FUN_0065c120(iVar9,&param_1,psVar17,0x106), iVar10 == 0)) ||
              (((*(uint *)(iVar9 + 0x28) & 0x200) != 0 &&
               (iVar10 = FUN_0065c120(iVar9,&param_1,psVar17,0x107), iVar10 == 0)))) ||
             (((*(uint *)(iVar9 + 0x28) & 0x400) != 0 &&
              (iVar10 = FUN_0065c120(iVar9,&param_1,psVar17,0x10a), iVar10 == 0)))))))))) ||
         ((((*(uint *)(iVar9 + 0x28) & 0x8000) != 0 &&
           (iVar10 = FUN_0065c120(iVar9,&param_1,psVar17,0x112), iVar10 == 0)) ||
          ((((((*(uint *)(iVar9 + 0x28) & 0x10000) != 0 &&
              (iVar10 = FUN_0065c120(iVar9,&param_1,psVar17,0x115), iVar10 == 0)) ||
             (((*(uint *)(iVar9 + 0x28) & 0x20000) != 0 &&
              (iVar10 = FUN_0065c540(iVar9,&param_1,psVar17,0x116,*(undefined4 *)(iVar9 + 100)),
              iVar10 == 0)))) ||
            ((((*(uint *)(iVar9 + 0x28) & 0x40000) != 0 &&
              (iVar10 = FUN_0065c1a0(iVar9,&param_1,psVar17,0x118), iVar10 == 0)) ||
             (((*(uint *)(iVar9 + 0x28) & 0x80000) != 0 &&
              (iVar10 = FUN_0065c1a0(iVar9,&param_1,psVar17,0x119), iVar10 == 0)))))) ||
           (((((*(uint *)(iVar9 + 0x28) & 0x100000) != 0 &&
              (iVar10 = FUN_0065c120(iVar9,&param_1,psVar17,0x11c), iVar10 == 0)) ||
             (((*(uint *)(iVar9 + 0x28) & 0x400000) != 0 &&
              (iVar10 = FUN_0065c120(iVar9,&param_1,psVar17,0x128), iVar10 == 0)))) ||
            (((*(uint *)(iVar9 + 0x28) & 0x800000) != 0 &&
             (iVar10 = FUN_0065c160(iVar9,&param_1,psVar17,0x129,2), iVar10 == 0))))))))))
      goto LAB_0065b989;
      if ((*(uint *)(iVar9 + 0x28) & 0x1000000) != 0) {
        if ((*(uint *)(iVar9 + 0xc) & 0x400) == 0) {
          iVar10 = FUN_0065c590(iVar9,&param_1,psVar17,0x117,*(undefined4 *)(iVar9 + 0xa8));
        }
        else {
          iVar10 = FUN_0065c590(iVar9,&param_1,psVar17,0x145,*(undefined4 *)(iVar9 + 0xa8));
        }
        if (iVar10 == 0) goto LAB_0065b989;
      }
      if ((*(uint *)(iVar9 + 0x28) & 0x2000000) != 0) {
        if ((*(uint *)(iVar9 + 0xc) & 0x400) == 0) {
          iVar10 = FUN_0065c590(iVar9,&param_1,psVar17,0x111,*(undefined4 *)(iVar9 + 0xa8));
        }
        else {
          iVar10 = FUN_0065c590(iVar9,&param_1,psVar17,0x144,*(undefined4 *)(iVar9 + 0xa8));
        }
        if (iVar10 == 0) goto LAB_0065b989;
      }
      if (((*(uint *)(iVar9 + 0x28) & 0x4000000) != 0) &&
         (iVar10 = FUN_0065c7b0(iVar9,&param_1), iVar10 == 0)) goto LAB_0065b989;
      if (((*(uint *)(iVar9 + 0x28) & 0x80000000) != 0) && (*(short *)(iVar9 + 0x9c) != 0)) {
        FUN_00651280(iVar9,0x152,&uStack_18);
        iVar10 = FUN_0065c160(iVar9,&param_1,psVar17,0x152,uStack_18 & 0xffff,uStack_1c);
        if (iVar10 == 0) goto LAB_0065b989;
      }
      if (((((((((*(byte *)(iVar9 + 0x2c) & 1) != 0) &&
               (iVar10 = FUN_0065c1a0(iVar9,&param_1,psVar17,0x153), iVar10 == 0)) ||
              (((*(byte *)(iVar9 + 0x2c) & 2) != 0 &&
               (iVar10 = FUN_0065bd80(iVar9,&param_1,psVar17,0x154,*(undefined2 *)(iVar9 + 0x62)),
               iVar10 == 0)))) ||
             (((*(byte *)(iVar9 + 0x2c) & 4) != 0 &&
              (iVar10 = FUN_0065bd80(iVar9,&param_1,psVar17,0x155,*(undefined2 *)(iVar9 + 0x62)),
              iVar10 == 0)))) ||
            (((*(byte *)(iVar9 + 0x2c) & 8) != 0 &&
             (iVar10 = FUN_0065c280(iVar9,&param_1,psVar17,0x80e5), iVar10 == 0)))) ||
           ((((*(byte *)(iVar9 + 0x2c) & 0x10) != 0 &&
             (iVar10 = FUN_0065c280(iVar9,&param_1,psVar17,0x80e6), iVar10 == 0)) ||
            (((*(byte *)(iVar9 + 0x2c) & 0x20) != 0 &&
             (iVar10 = FUN_0065c160(iVar9,&param_1,psVar17,0x141,2), iVar10 == 0)))))) ||
          ((((*(byte *)(iVar9 + 0x2c) & 0x80) != 0 &&
            (iVar10 = FUN_0065c160(iVar9,&param_1,psVar17,0x212,2), iVar10 == 0)) ||
           (((*(uint *)(iVar9 + 0x2c) & 0x100) != 0 &&
            (iVar10 = FUN_0065c120(iVar9,&param_1,psVar17,0x213), iVar10 == 0)))))) ||
         (((((*(uint *)(iVar9 + 0x2c) & 0x200) != 0 &&
            (iVar10 = FUN_0065c400(iVar9,&param_1,psVar17,0x214,6), iVar10 == 0)) ||
           (((*(uint *)(iVar9 + 0x2c) & 0x1000) != 0 &&
            (iVar10 = FUN_0065c870(iVar9,&param_1), iVar10 == 0)))) ||
          ((((*(uint *)(iVar9 + 0x2c) & 0x4000) != 0 &&
            (iVar10 = FUN_0065c020(iVar9,&param_1,psVar17,0x14d,*(undefined4 *)(iVar9 + 0xd8)),
            iVar10 == 0)) ||
           (((*(uint *)(iVar9 + 0x2c) & 0x20000) != 0 &&
            (iVar10 = FUN_0065c9e0(iVar9,&param_1), iVar10 == 0)))))))) goto LAB_0065b989;
      uStack_20 = 0;
      if (*(int *)(iVar9 + 0x294) != 0) {
        do {
          puVar4 = *(undefined4 **)(*(int *)(iVar9 + 0x290) + uStack_20 * 4);
          uVar2 = *(ushort *)(puVar4 + 6);
          if ((uVar2 < 0x42) ||
             ((*(uint *)(iVar9 + 0x28 + (uint)(uVar2 >> 5) * 4) & 1 << ((byte)uVar2 & 0x1f)) == 0))
          goto switchD_0065b462_caseD_2;
          switch(puVar4[5]) {
          case 1:
            FUN_0064e2c0(iVar9,*puVar4);
            uVar14 = 0xffffffff;
            pcVar18 = pcStack_14;
            do {
              if (uVar14 == 0) break;
              uVar14 = uVar14 - 1;
              cVar1 = *pcVar18;
              pcVar18 = pcVar18 + 1;
            } while (cVar1 != '\0');
            iVar10 = FUN_0065c020(iVar9,&param_1,psVar17,
                                  CONCAT22((short)(~uVar14 - 1 >> 0x10),*(undefined2 *)puVar4),
                                  ~uVar14 - 1,pcStack_14);
            break;
          default:
            goto switchD_0065b462_caseD_2;
          case 4:
            FUN_0064e2c0(iVar9,*puVar4);
            iVar10 = FUN_0065c120(iVar9,&param_1,psVar17,
                                  CONCAT22(extraout_var,*(undefined2 *)puVar4),uStack_10);
            break;
          case 6:
            FUN_0064e2c0(iVar9,*puVar4);
            iVar10 = FUN_0065c280(iVar9,&param_1,psVar17,
                                  CONCAT22(extraout_var_01,*(undefined2 *)puVar4),uStack_c);
            goto joined_r0x0065b53f;
          case 0x28:
            FUN_0064e2c0(iVar9,*puVar4,&uStack_4);
            iVar10 = FUN_0065c060(iVar9,&param_1,psVar17,
                                  CONCAT22(extraout_var_00,*(undefined2 *)puVar4),uStack_4,uStack_8)
            ;
joined_r0x0065b53f:
            if (iVar10 != 0) goto switchD_0065b462_caseD_2;
            goto LAB_0065b989;
          }
          if (iVar10 == 0) goto LAB_0065b989;
switchD_0065b462_caseD_2:
          uStack_20 = uStack_20 + 1;
        } while (uStack_20 < *(uint *)(iVar9 + 0x294));
      }
    }
    uVar14 = 0;
    if (*(int *)(iVar9 + 0xe0) != 0) {
      iVar10 = 0;
      do {
        puVar5 = *(undefined2 **)(iVar10 + *(int *)(iVar9 + 0xe4));
        iVar11 = iVar10 + *(int *)(iVar9 + 0xe4);
        uVar13 = (undefined2)((uint)puVar5 >> 0x10);
        switch(*(undefined4 *)(puVar5 + 4)) {
        case 1:
          iVar11 = FUN_0065c0a0(iVar9,&param_1,psVar17,CONCAT22(uVar13,*puVar5),
                                *(undefined4 *)(iVar11 + 4));
          goto joined_r0x0065b5a7;
        case 2:
          iVar11 = FUN_0065c020(iVar9,&param_1,psVar17,CONCAT22(uVar13,*puVar5),
                                *(undefined4 *)(iVar11 + 4));
joined_r0x0065b5a7:
          if (iVar11 != 0) goto switchD_0065b583_caseD_e;
          goto LAB_0065b989;
        case 3:
          iVar11 = FUN_0065c160(iVar9,&param_1,psVar17,CONCAT22(uVar13,*puVar5),
                                *(undefined4 *)(iVar11 + 4));
          break;
        case 4:
          iVar11 = FUN_0065c2c0(iVar9,&param_1,psVar17,CONCAT22(uVar13,*puVar5),
                                *(undefined4 *)(iVar11 + 4));
          break;
        case 5:
          iVar11 = FUN_0065c400(iVar9,&param_1,psVar17,CONCAT22(uVar13,*puVar5),
                                *(undefined4 *)(iVar11 + 4));
          break;
        case 6:
          iVar11 = FUN_0065c0e0(iVar9,&param_1,psVar17,CONCAT22(uVar13,*puVar5),
                                *(undefined4 *)(iVar11 + 4));
          break;
        case 7:
          iVar11 = FUN_0065c060(iVar9,&param_1,psVar17,CONCAT22(uVar13,*puVar5),
                                *(undefined4 *)(iVar11 + 4));
          break;
        case 8:
          iVar11 = FUN_0065c240(iVar9,&param_1,psVar17,CONCAT22(uVar13,*puVar5),
                                *(undefined4 *)(iVar11 + 4));
          break;
        case 9:
          iVar11 = FUN_0065c300(iVar9,&param_1,psVar17,CONCAT22(uVar13,*puVar5),
                                *(undefined4 *)(iVar11 + 4));
          break;
        case 10:
          iVar11 = FUN_0065c440(iVar9,&param_1,psVar17,CONCAT22(uVar13,*puVar5),
                                *(undefined4 *)(iVar11 + 4));
          break;
        case 0xb:
          iVar11 = FUN_0065c480(iVar9,&param_1,psVar17,CONCAT22(uVar13,*puVar5),
                                *(undefined4 *)(iVar11 + 4));
          break;
        case 0xc:
          iVar11 = FUN_0065c4c0(iVar9,&param_1,psVar17,CONCAT22(uVar13,*puVar5),
                                *(undefined4 *)(iVar11 + 4));
          break;
        case 0xd:
          iVar11 = FUN_0065c500(iVar9,&param_1,psVar17,CONCAT22(uVar13,*puVar5),
                                *(undefined4 *)(iVar11 + 4));
          break;
        default:
          goto switchD_0065b583_caseD_e;
        case 0x10:
          iVar11 = FUN_0065c340(iVar9,&param_1,psVar17,CONCAT22(uVar13,*puVar5),
                                *(undefined4 *)(iVar11 + 4));
          break;
        case 0x11:
          iVar11 = FUN_0065c380(iVar9,&param_1,psVar17,CONCAT22(uVar13,*puVar5),
                                *(undefined4 *)(iVar11 + 4));
          break;
        case 0x12:
          iVar11 = FUN_0065c6a0(iVar9,&param_1,psVar17,CONCAT22(uVar13,*puVar5),
                                *(undefined4 *)(iVar11 + 4));
        }
        if (iVar11 == 0) goto LAB_0065b989;
switchD_0065b583_caseD_e:
        uVar14 = uVar14 + 1;
        iVar10 = iVar10 + 0xc;
      } while (uVar14 < *(uint *)(iVar9 + 0xe0));
    }
    if (psVar17 != (short *)0x0) {
      if (((param_2 != 0) && ((*(uint *)(iVar9 + 0x2c) & 0x20000) != 0)) &&
         (*(int *)(iVar9 + 0x1e0) == 0 && *(int *)(iVar9 + 0x1e4) == 0)) {
        iVar10 = 0;
        sVar3 = *psVar17;
        psVar15 = psVar17;
        while (sVar3 != 0x14a) {
          psVar15 = psVar15 + 0xc;
          iVar10 = iVar10 + 1;
          sVar3 = *psVar15;
        }
        if ((*(uint *)(iVar9 + 0xc) & 0x80000) == 0) {
          uVar14 = iVar10 * 0xc + *(uint *)(iVar9 + 0x10);
          *(uint *)(iVar9 + 0x1e0) = uVar14 + 10;
          *(uint *)(iVar9 + 0x1e4) =
               *(int *)(iVar9 + 0x14) + (uint)CARRY4(iVar10 * 0xc,*(uint *)(iVar9 + 0x10)) +
               (uint)(0xfffffff5 < uVar14);
        }
        else {
          uVar14 = iVar10 * 0x14 + *(uint *)(iVar9 + 0x10);
          *(uint *)(iVar9 + 0x1e0) = uVar14 + 0x14;
          *(uint *)(iVar9 + 0x1e4) =
               *(int *)(iVar9 + 0x14) + (uint)CARRY4(iVar10 * 0x14,*(uint *)(iVar9 + 0x10)) +
               (uint)(0xffffffeb < uVar14);
        }
      }
      puVar12 = (uint *)FUN_006507d0();
      if (puVar12 != (uint *)0x0) {
        if ((*(uint *)(iVar9 + 0xc) & 0x80000) == 0) {
          *(undefined2 *)puVar12 = (undefined2)param_1;
          if ((*(byte *)(iVar9 + 0xc) & 0x80) != 0) {
            FUN_0065a5f0();
          }
          psVar15 = (short *)((int)puVar12 + 2);
          param_2 = 0;
          if (param_1 != 0) {
            psVar17 = psVar17 + 4;
            do {
              *psVar15 = psVar17[-4];
              if ((*(byte *)(iVar9 + 0xc) & 0x80) != 0) {
                FUN_0065a5f0();
              }
              psVar15[1] = psVar17[-3];
              if ((*(byte *)(iVar9 + 0xc) & 0x80) != 0) {
                FUN_0065a5f0();
              }
              param_4 = *(undefined4 **)psVar17;
              FUN_00650840(psVar15 + 2,&param_4,4);
              if ((*(byte *)(iVar9 + 0xc) & 0x80) != 0) {
                FUN_0065a600();
              }
              FUN_00650840(psVar15 + 4,psVar17 + 4,4);
              psVar15 = psVar15 + 6;
              psVar17 = psVar17 + 0xc;
              param_2 = param_2 + 1;
            } while (param_2 < param_1);
          }
          param_4 = *(undefined4 **)(iVar9 + 0x18);
          if ((*(byte *)(iVar9 + 0xc) & 0x80) != 0) {
            FUN_0065a600();
          }
          FUN_00650840(psVar15,&param_4,4);
        }
        else {
          *puVar12 = param_1;
          puVar12[1] = 0;
          if ((*(byte *)(iVar9 + 0xc) & 0x80) != 0) {
            FUN_0065a620();
          }
          puVar16 = puVar12 + 2;
          param_2 = 0;
          if (param_1 != 0) {
            psVar17 = psVar17 + 4;
            do {
              *(short *)puVar16 = psVar17[-4];
              if ((*(byte *)(iVar9 + 0xc) & 0x80) != 0) {
                FUN_0065a5f0();
              }
              *(short *)((int)puVar16 + 2) = psVar17[-3];
              if ((*(byte *)(iVar9 + 0xc) & 0x80) != 0) {
                FUN_0065a5f0();
              }
              FUN_00650840(puVar16 + 1,psVar17,8);
              if ((*(byte *)(iVar9 + 0xc) & 0x80) != 0) {
                FUN_0065a620();
              }
              FUN_00650840(puVar16 + 3,psVar17 + 4,8);
              puVar16 = puVar16 + 5;
              psVar17 = psVar17 + 0xc;
              param_2 = param_2 + 1;
            } while (param_2 < param_1);
          }
          FUN_00650840(puVar16,iVar9 + 0x18,8);
          if ((*(byte *)(iVar9 + 0xc) & 0x80) != 0) {
            FUN_0065a620();
          }
        }
        FUN_006507e0();
        uVar20 = (**(code **)(iVar9 + 0x280))
                           (*(undefined4 *)(iVar9 + 0x274),*(undefined4 *)(iVar9 + 0x10),
                            *(undefined4 *)(iVar9 + 0x14),0);
        if (((int)uVar20 != *(int *)(iVar9 + 0x10)) ||
           ((int)((ulonglong)uVar20 >> 0x20) != *(int *)(iVar9 + 0x14))) {
          FUN_006512e0(*(undefined4 *)(iVar9 + 0x274),"TIFFWriteDirectorySec",
                       s_IO_error_writing_directory_00a0a680);
          FUN_006507e0();
          return 0;
        }
        uVar14 = (**(code **)(iVar9 + 0x27c))(*(undefined4 *)(iVar9 + 0x274),puVar12,local_24);
        if (uVar14 != local_24) {
          FUN_006512e0(*(undefined4 *)(iVar9 + 0x274),"TIFFWriteDirectorySec",
                       s_IO_error_writing_directory_00a0a680);
          FUN_006507e0();
          return 0;
        }
        FUN_006507e0();
        if (param_3 == 0) {
          return 1;
        }
        FUN_0064e340();
        *(uint *)(iVar9 + 0xc) = *(uint *)(iVar9 + 0xc) & 0xffdffff7;
        (**(code **)(iVar9 + 0x234))(iVar9);
        FUN_0064e500(iVar9);
        return 1;
      }
      uVar21 = *(undefined4 *)(iVar9 + 0x274);
      uVar20 = 0xa066e400804f90;
      goto LAB_0065b981;
    }
    psVar17 = (short *)FUN_006507d0();
    if (psVar17 == (short *)0x0) {
      FUN_006512e0(*(undefined4 *)(iVar9 + 0x274),"TIFFWriteDirectorySec",s_Out_of_memory_00a066e4);
      return 0;
    }
    if (param_2 == 0) {
      lVar19 = (**(code **)(iVar9 + 0x280))(*(undefined4 *)(iVar9 + 0x274),0);
      *(uint *)(iVar9 + 0x10) = (uint)(lVar19 + 1) & 0xfffffffe;
      *(int *)(iVar9 + 0x14) = (int)((ulonglong)(lVar19 + 1) >> 0x20);
    }
    else if ((*(int *)(iVar9 + 0x10) == 0 && *(int *)(iVar9 + 0x14) == 0) &&
            (iVar10 = FUN_0065d600(), iVar10 == 0)) goto LAB_0065b989;
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = *(undefined4 *)(iVar9 + 0x10);
      param_4[1] = *(undefined4 *)(iVar9 + 0x14);
    }
    uVar14 = *(uint *)(iVar9 + 0xc) & 0x80000;
    if (uVar14 == 0) {
      local_24 = param_1 * 0xc + 6;
    }
    else {
      local_24 = param_1 * 0x14 + 0x10;
    }
    uVar6 = *(uint *)(iVar9 + 0x10);
    uVar7 = *(uint *)(iVar9 + 0x14);
    *(uint *)(iVar9 + 0x1d0) = local_24 + uVar6;
    *(uint *)(iVar9 + 0x1d4) = uVar7 + CARRY4(local_24,uVar6);
    if (uVar14 == 0) {
      *(undefined4 *)(iVar9 + 0x1d0) = *(undefined4 *)(iVar9 + 0x1d0);
      *(undefined4 *)(iVar9 + 0x1d4) = 0;
    }
    uVar14 = *(uint *)(iVar9 + 0x1d4);
    uVar8 = *(uint *)(iVar9 + 0x1d0);
    if (((uVar14 < uVar7) || ((uVar14 <= uVar7 && (uVar8 < uVar6)))) ||
       ((uVar14 == 0 && (uVar8 < local_24)))) {
      uVar21 = *(undefined4 *)(iVar9 + 0x274);
      uVar20 = 0xa0a69c00804f90;
LAB_0065b981:
      FUN_006512e0(uVar21,uVar20);
LAB_0065b989:
      if (psVar17 == (short *)0x0) {
        return 0;
      }
      FUN_006507e0();
      return 0;
    }
    if ((uVar8 & 1) != 0) {
      *(uint *)(iVar9 + 0x1d0) = uVar8 + 1;
      *(uint *)(iVar9 + 0x1d4) = uVar14 + (0xfffffffe < uVar8);
    }
    if (param_2 != 0) {
      *(short *)(iVar9 + 0x1c0) = *(short *)(iVar9 + 0x1c0) + 1;
    }
  } while( true );
}

