//
//  ulibgsmmap.h
//  ulibgsmmap
//
//  Copyright © 2017 Andreas Fink (andreas@fink.org). All rights reserved.
//
// This source is dual licensed either under the GNU GENERAL PUBLIC LICENSE
// Version 3 from 29 June 2007 and other commercial licenses available by
// the author.
//

#import <ulibtcap/ulibtcap.h>

#import "GsmCharSet.h"
#import "NSString+map.h"
#import "NSData+map.h"
#import "UMLayerGSMMAP.h"
#import "UMLayerGSMMAPApplicationContextProtocol.h"

#import "UMLayerGSMMAP_Dialog.h"
#import "UMLayerGSMMAP_UserProtocol.h"
#import "UMLayerGSMMAP_ProviderProtocol.h"
#import "UMLayerGSMMAP_OpCode.h"
#import "UMLayerGSMMAP_ErrorCode.h"
#import "UMGSMMAP_DialogIdentifier.h"
#import "UMGSMMAP_UserIdentifier.h"

#import "UMGSMMAP_APN.h"
#import "UMGSMMAP_ASCI_CallReference.h"
#import "UMGSMMAP_ASNTime.h"
#import "UMGSMMAP_ASNTimeZone.h"
#import "UMGSMMAP_AUTN.h"
#import "UMGSMMAP_AbsentSubscriberDiagnosticSM.h"
#import "UMGSMMAP_AbsentSubscriberParam.h"
#import "UMGSMMAP_AbsentSubscriberReason.h"
#import "UMGSMMAP_AbsentSubscriberSM_Param.h"
#import "UMGSMMAP_ActivateTraceModeArg.h"
#import "UMGSMMAP_ActivateTraceModeRes.h"
#import "UMGSMMAP_Additional_Number.h"
#import "UMGSMMAP_AddressString.h"
#import "UMGSMMAP_AgeOfLocationInformation.h"
#import "UMGSMMAP_AlertReason.h"
#import "UMGSMMAP_AlertServiceCentreArg.h"
#import "UMGSMMAP_AlertingPattern.h"
#import "UMGSMMAP_AnyTimeInterrogationArg.h"
#import "UMGSMMAP_AnyTimeInterrogationRes.h"
#import "UMGSMMAP_ApplicationContexts.h"
#import "UMGSMMAP_Ati_NotAllowedParam.h"
#import "UMGSMMAP_AuthenticationFailureReportArg.h"
#import "UMGSMMAP_AuthenticationFailureReportRes.h"
#import "UMGSMMAP_AuthenticationQuintuplet.h"
#import "UMGSMMAP_AuthenticationQuintupletList.h"
#import "UMGSMMAP_AuthenticationSetList.h"
#import "UMGSMMAP_AuthenticationTriplet.h"
#import "UMGSMMAP_AuthenticationTripletList.h"
#import "UMGSMMAP_BasicServiceCode.h"
#import "UMGSMMAP_BasicServiceCriteria.h"
#import "UMGSMMAP_BasicServiceGroupList.h"
#import "UMGSMMAP_BasicServiceList.h"
#import "UMGSMMAP_BearerServNotProvParam.h"
#import "UMGSMMAP_BearerServiceCode.h"
#import "UMGSMMAP_BearerServiceList.h"
#import "UMGSMMAP_BusySubscriberParam.h"
#import "UMGSMMAP_CCBS_Data.h"
#import "UMGSMMAP_CCBS_Feature.h"
#import "UMGSMMAP_CCBS_FeatureList.h"
#import "UMGSMMAP_CCBS_Index.h"
#import "UMGSMMAP_CCBS_Indicators.h"
#import "UMGSMMAP_CCBS_SubscriberStatus.h"
#import "UMGSMMAP_CK.h"
#import "UMGSMMAP_CKSN.h"
#import "UMGSMMAP_CODEC_Info.h"
#import "UMGSMMAP_CSG_Id.h"
#import "UMGSMMAP_CUG_CheckInfo.h"
#import "UMGSMMAP_CUG_Feature.h"
#import "UMGSMMAP_CUG_FeatureList.h"
#import "UMGSMMAP_CUG_Index.h"
#import "UMGSMMAP_CUG_Info.h"
#import "UMGSMMAP_CUG_Interlock.h"
#import "UMGSMMAP_CUG_RejectCause.h"
#import "UMGSMMAP_CUG_Subscription.h"
#import "UMGSMMAP_CUG_SubscriptionList.h"
#import "UMGSMMAP_CallBarredParam.h"
#import "UMGSMMAP_CallBarringCause.h"
#import "UMGSMMAP_CallBarringFeature.h"
#import "UMGSMMAP_CallBarringFeatureList.h"
#import "UMGSMMAP_CallBarringInfo.h"
#import "UMGSMMAP_CallDirection.h"
#import "UMGSMMAP_CallOutcome.h"
#import "UMGSMMAP_CallReferenceNumber.h"
#import "UMGSMMAP_CallReportData.h"
#import "UMGSMMAP_CallTypeCriteria.h"
#import "UMGSMMAP_CamelCapabilityHandling.h"
#import "UMGSMMAP_CamelInfo.h"
#import "UMGSMMAP_CamelRoutingInfo.h"
#import "UMGSMMAP_CancelLocationArg.h"
#import "UMGSMMAP_CancelLocationRes.h"
#import "UMGSMMAP_CancellationType.h"
#import "UMGSMMAP_Category.h"
#import "UMGSMMAP_CellGlobalIdOrServiceAreaIdOrLAI.h"
#import "UMGSMMAP_CellIdFixedLength.h"
#import "UMGSMMAP_CellIdOrLAI.h"
#import "UMGSMMAP_ChargingCharacteristics.h"
#import "UMGSMMAP_CipheringAlgorithm.h"
#import "UMGSMMAP_CliRestrictionOption.h"
#import "UMGSMMAP_Code.h"
#import "UMGSMMAP_Constants.h"
#import "UMGSMMAP_ContextId.h"
#import "UMGSMMAP_ContextIdList.h"
#import "UMGSMMAP_Cug_RejectParam.h"
#import "UMGSMMAP_CurrentPassword.h"
#import "UMGSMMAP_CurrentSecurityContext.h"
#import "UMGSMMAP_DataMissingParam.h"
#import "UMGSMMAP_DaylightSavingTime.h"
#import "UMGSMMAP_DeactivateTraceModeArg.h"
#import "UMGSMMAP_DeactivateTraceModeRes.h"
#import "UMGSMMAP_DefaultCallHandling.h"
#import "UMGSMMAP_DeferredLocationEventType.h"
#import "UMGSMMAP_DeleteSubscriberDataArg.h"
#import "UMGSMMAP_DeleteSubscriberDataRes.h"
#import "UMGSMMAP_DestinationNumberCriteria.h"
#import "UMGSMMAP_DestinationNumberLengthList.h"
#import "UMGSMMAP_DestinationNumberList.h"
#import "UMLayerGSMMAP_Dialog.h"
#import "UMGSMMAP_DiameterIdentity.h"
#import "UMGSMMAP_EMLPP_Info.h"
#import "UMGSMMAP_EMLPP_Priority.h"
#import "UMGSMMAP_E_UTRAN_CGI.h"
#import "UMGSMMAP_Eps_AuthenticationSet.h"
#import "UMGSMMAP_Eps_AuthenticationSetList.h"
#import "UMGSMMAP_EquipmentStatus.h"
#import "UMGSMMAP_EraseCC_EntryArg.h"
#import "UMGSMMAP_EraseCC_EntryRes.h"
#import "UMGSMMAP_EventReportData.h"
#import "UMGSMMAP_Ext2_QoS_Subscribed.h"
#import "UMGSMMAP_Ext3_QoS_Subscribed.h"
#import "UMGSMMAP_Ext4_QoS_Subscribed.h"
#import "UMGSMMAP_Ext_BasicServiceCode.h"
#import "UMGSMMAP_Ext_BasicServiceGroupList.h"
#import "UMGSMMAP_Ext_BearerServiceCode.h"
#import "UMGSMMAP_Ext_CallBarFeatureList.h"
#import "UMGSMMAP_Ext_CallBarInfo.h"
#import "UMGSMMAP_Ext_CallBarringFeature.h"
#import "UMGSMMAP_Ext_ExternalSignalInfo.h"
#import "UMGSMMAP_Ext_ForwFeature.h"
#import "UMGSMMAP_Ext_ForwFeatureList.h"
#import "UMGSMMAP_Ext_ForwInfo.h"
#import "UMGSMMAP_Ext_ForwOptions.h"
#import "UMGSMMAP_Ext_GeographicalInformation.h"
#import "UMGSMMAP_Ext_NoRepCondTime.h"
#import "UMGSMMAP_Ext_PDP_Type.h"
#import "UMGSMMAP_Ext_ProtocolId.h"
#import "UMGSMMAP_Ext_QoS_Subscribed.h"
#import "UMGSMMAP_Ext_SS_Data.h"
#import "UMGSMMAP_Ext_SS_Info.h"
#import "UMGSMMAP_Ext_SS_InfoList.h"
#import "UMGSMMAP_Ext_SS_Status.h"
#import "UMGSMMAP_Ext_TeleserviceCode.h"
#import "UMGSMMAP_ExtendedRoutingInfo.h"
#import "UMGSMMAP_ExtensibleCallBarredParam.h"
#import "UMGSMMAP_ExtensibleSystemFailureParam.h"
#import "UMGSMMAP_ExtensionContainer.h"
#import "UMGSMMAP_ExternalClient.h"
#import "UMGSMMAP_ExternalClientList.h"
#import "UMGSMMAP_ExternalSignalInfo.h"
#import "UMGSMMAP_FacilityNotSupParam.h"
#import "UMGSMMAP_FailureReportArg.h"
#import "UMGSMMAP_FailureReportRes.h"
#import "UMGSMMAP_ForwardGroupCallSignallingArg.h"
#import "UMGSMMAP_ForwardingData.h"
#import "UMGSMMAP_ForwardingFailedParam.h"
#import "UMGSMMAP_ForwardingFeature.h"
#import "UMGSMMAP_ForwardingFeatureList.h"
#import "UMGSMMAP_ForwardingInfo.h"
#import "UMGSMMAP_ForwardingOptions.h"
#import "UMGSMMAP_ForwardingReason.h"
#import "UMGSMMAP_ForwardingViolationParam.h"
#import "UMGSMMAP_GMLC_List.h"
#import "UMGSMMAP_GMLC_Restriction.h"
#import "UMGSMMAP_GPRSChargingID.h"
#import "UMGSMMAP_GPRSDataList.h"
#import "UMGSMMAP_GPRSMSClass.h"
#import "UMGSMMAP_GPRSSubscriptionData.h"
#import "UMGSMMAP_GPRSSubscriptionDataWithdraw.h"
#import "UMGSMMAP_GSM_SecurityContextData.h"
#import "UMGSMMAP_GSN_Address.h"
#import "UMGSMMAP_GenericServiceInfo.h"
#import "UMGSMMAP_GeodeticInformation.h"
#import "UMGSMMAP_GeographicalInformation.h"
#import "UMGSMMAP_GlobalCellId.h"
#import "UMGSMMAP_GmscCamelSubscriptionInfo.h"
#import "UMGSMMAP_GroupId.h"
#import "UMGSMMAP_GroupKeyNumber.h"
#import "UMGSMMAP_GuidanceInfo.h"
#import "UMGSMMAP_HLR_Id.h"
#import "UMGSMMAP_HLR_List.h"
#import "UMGSMMAP_Horizontal_Accuracy.h"
#import "UMGSMMAP_IK.h"
#import "UMGSMMAP_IMEI.h"
#import "UMGSMMAP_IMSI.h"
#import "UMGSMMAP_IMSI_WithLMSI.h"
#import "UMGSMMAP_IMS_VoiceOverPS_SessionsInd.h"
#import "UMGSMMAP_ISDN_AddressString.h"
#import "UMGSMMAP_ISDN_SubaddressString.h"
#import "UMGSMMAP_IST_AlertArg.h"
#import "UMGSMMAP_IST_AlertRes.h"
#import "UMGSMMAP_IST_CommandArg.h"
#import "UMGSMMAP_IST_CommandRes.h"
#import "UMGSMMAP_Identity.h"
#import "UMGSMMAP_IllegalEquipmentParam.h"
#import "UMGSMMAP_IllegalSubscriberParam.h"
#import "UMGSMMAP_IncompatibleTerminalParam.h"
#import "UMGSMMAP_InformServiceCentreArg.h"
#import "UMGSMMAP_InsertSubscriberDataArg.h"
#import "UMGSMMAP_InsertSubscriberDataRes.h"
#import "UMGSMMAP_InterCUG_Restrictions.h"
#import "UMGSMMAP_InterrogateSS_Res.h"
#import "UMGSMMAP_InterrogationType.h"
#import "UMGSMMAP_IntraCUG_Options.h"
#import "UMGSMMAP_KSI.h"
#import "UMGSMMAP_Kc.h"
#import "UMGSMMAP_LAIFixedLength.h"
#import "UMGSMMAP_LCSClientExternalID.h"
#import "UMGSMMAP_LCSClientInternalID.h"
#import "UMGSMMAP_LCSClientName.h"
#import "UMGSMMAP_LCSClientType.h"
#import "UMGSMMAP_LCSCodeword.h"
#import "UMGSMMAP_LCSInformation.h"
#import "UMGSMMAP_LCSLocationInfo.h"
#import "UMGSMMAP_LCSRequestorID.h"
#import "UMGSMMAP_LCSServiceTypeID.h"
#import "UMGSMMAP_LCS_ClientID.h"
#import "UMGSMMAP_LCS_Event.h"
#import "UMGSMMAP_LCS_Priority.h"
#import "UMGSMMAP_LCS_PrivacyCheck.h"
#import "UMGSMMAP_LCS_PrivacyClass.h"
#import "UMGSMMAP_LCS_PrivacyExceptionList.h"
#import "UMGSMMAP_LCS_QoS.h"
#import "UMGSMMAP_LCS_ReferenceNumber.h"
#import "UMGSMMAP_LMSI.h"
#import "UMGSMMAP_LSAAttributes.h"
#import "UMGSMMAP_LSAData.h"
#import "UMGSMMAP_LSADataList.h"
#import "UMGSMMAP_LSAIdentity.h"
#import "UMGSMMAP_LSAIdentityList.h"
#import "UMGSMMAP_LSAInformation.h"
#import "UMGSMMAP_LSAInformationWithdraw.h"
#import "UMGSMMAP_LSAOnlyAccessIndicator.h"
#import "UMGSMMAP_LocationEstimateType.h"
#import "UMGSMMAP_LocationInfoWithLMSI.h"
#import "UMGSMMAP_LocationInformation.h"
#import "UMGSMMAP_LocationInformationEPS.h"
#import "UMGSMMAP_LocationInformationGPRS.h"
#import "UMGSMMAP_LocationNumber.h"
#import "UMGSMMAP_LocationType.h"
#import "UMGSMMAP_LongTermDenialParam.h"
#import "UMGSMMAP_MAP_PDU.h"
#import "UMGSMMAP_MNPInfoRes.h"
#import "UMGSMMAP_MOLR_Class.h"
#import "UMGSMMAP_MOLR_List.h"
#import "UMGSMMAP_MO_ForwardSM_Arg.h"
#import "UMGSMMAP_MO_ForwardSM_Res.h"
#import "UMGSMMAP_MSNetworkCapability.h"
#import "UMGSMMAP_MSRadioAccessCapability.h"
#import "UMGSMMAP_MS_Classmark2.h"
#import "UMGSMMAP_MT_ForwardSM_Arg.h"
#import "UMGSMMAP_MT_ForwardSM_Res.h"
#import "UMGSMMAP_MW_Status.h"
#import "UMGSMMAP_Macros.h"
#import "UMGSMMAP_MatchType.h"
#import "UMGSMMAP_MessageWaitListFullParam.h"
#import "UMGSMMAP_MonitoringMode.h"
#import "UMGSMMAP_Msisdn.h"
#import "UMGSMMAP_NAEA_CIC.h"
#import "UMGSMMAP_NAEA_PreferredCI.h"
#import "UMGSMMAP_NSAPI.h"
#import "UMGSMMAP_NameString.h"
#import "UMGSMMAP_NetDetNotReachable.h"
#import "UMGSMMAP_NetworkAccessMode.h"
#import "UMGSMMAP_NetworkResource.h"
#import "UMGSMMAP_NewPassword.h"
#import "UMGSMMAP_NoGroupCallNbParam.h"
#import "UMGSMMAP_NoReplyConditionTime.h"
#import "UMGSMMAP_NoRoamingNbParam.h"
#import "UMGSMMAP_NoSubscriberReplyParam.h"
#import "UMGSMMAP_NotReachableReason.h"
#import "UMGSMMAP_NoteMsPresentForGprsArg.h"
#import "UMGSMMAP_NoteMsPresentForGprsRes.h"
#import "UMGSMMAP_NotificationToMSUser.h"
#import "UMGSMMAP_NumberChangedParam.h"
#import "UMGSMMAP_NumberOfForwarding.h"
#import "UMGSMMAP_NumberOfRequestedVectors.h"
#import "UMGSMMAP_NumberPortabilityStatus.h"
#import "UMGSMMAP_ODB_Data.h"
#import "UMGSMMAP_ODB_GeneralData.h"
#import "UMGSMMAP_ODB_HPLMN_Data.h"
#import "UMGSMMAP_OR_Phase.h"
#import "UMGSMMAP_O_BcsmCamelTDPCriteriaList.h"
#import "UMGSMMAP_O_BcsmCamelTDPData.h"
#import "UMGSMMAP_O_BcsmCamelTDPDataList.h"
#import "UMGSMMAP_O_BcsmCamelTDP_Criteria.h"
#import "UMGSMMAP_O_BcsmTriggerDetectionPoint.h"
#import "UMGSMMAP_O_CSI.h"
#import "UMGSMMAP_OldRoutingInfoForSM_Arg.h"
#import "UMGSMMAP_Opcodes.h"
#import "UMGSMMAP_Or_NotAllowedParam.h"
#import "UMGSMMAP_OverrideCategory.h"
#import "UMGSMMAP_PCS_Extensions.h"
#import "UMGSMMAP_PDP_Address.h"
#import "UMGSMMAP_PDP_Context.h"
#import "UMGSMMAP_PDP_ContextInfo.h"
#import "UMGSMMAP_PDP_ContextInfoList.h"
#import "UMGSMMAP_PDP_Type.h"
#import "UMGSMMAP_PLMNClientList.h"
#import "UMGSMMAP_PS_SubscriberState.h"
#import "UMGSMMAP_PeriodicLDRInfo.h"
#import "UMGSMMAP_PositionMethodFailure_Diagnostic.h"
#import "UMGSMMAP_PositionMethodFailure_Param.h"
#import "UMGSMMAP_PrepareGroupCallArg.h"
#import "UMGSMMAP_PrepareGroupCallRes.h"
#import "UMGSMMAP_PrepareHO_Arg.h"
#import "UMGSMMAP_PrepareHO_Res.h"
#import "UMGSMMAP_PrepareSubsequentHO_Arg.h"
#import "UMGSMMAP_Priority.h"
#import "UMGSMMAP_PrivateExtension.h"
#import "UMGSMMAP_PrivateExtensionList.h"
#import "UMGSMMAP_ProcessGroupCallSignallingArg.h"
#import "UMGSMMAP_ProtocolId.h"
#import "UMGSMMAP_ProvideRoamingNumberArg.h"
#import "UMGSMMAP_ProvideRoamingNumberRes.h"
#import "UMGSMMAP_ProvideSIWFSNumberArg.h"
#import "UMGSMMAP_ProvideSIWFSNumberRes.h"
#import "UMGSMMAP_ProvideSubscriberInfoArg.h"
#import "UMGSMMAP_ProvideSubscriberInfoRes.h"
#import "UMGSMMAP_ProvideSubscriberLocation_Arg.h"
#import "UMGSMMAP_ProvideSubscriberLocation_Res.h"
#import "UMGSMMAP_PurgeMS_Arg.h"
#import "UMGSMMAP_PurgeMS_Res.h"
#import "UMGSMMAP_Pw_RegistrationFailureCause.h"
#import "UMGSMMAP_QoS_Subscribed.h"
#import "UMGSMMAP_RAIdentity.h"
#import "UMGSMMAP_RAND.h"
#import "UMGSMMAP_RUF_Outcome.h"
#import "UMGSMMAP_Re_SynchronisationInfo.h"
#import "UMGSMMAP_ReadyForSM_Arg.h"
#import "UMGSMMAP_ReadyForSM_Res.h"
#import "UMGSMMAP_RegionalSubscriptionResponse.h"
#import "UMGSMMAP_RegisterCC_EntryArg.h"
#import "UMGSMMAP_RegisterCC_EntryRes.h"
#import "UMGSMMAP_RegisterSS_Arg.h"
#import "UMGSMMAP_RemoteUserFreeArg.h"
#import "UMGSMMAP_RemoteUserFreeRes.h"
#import "UMGSMMAP_ReportSM_DeliveryStatusArg.h"
#import "UMGSMMAP_ReportSM_DeliveryStatusRes.h"
#import "UMGSMMAP_ReportingPLMNList.h"
#import "UMGSMMAP_ReportingState.h"
#import "UMGSMMAP_RequestedInfo.h"
#import "UMGSMMAP_ResetArg.h"
#import "UMGSMMAP_ResourceLimitationParam.h"
#import "UMGSMMAP_ResponseTime.h"
#import "UMGSMMAP_ResponseTimeCategory.h"
#import "UMGSMMAP_RestoreDataArg.h"
#import "UMGSMMAP_RestoreDataRes.h"
#import "UMGSMMAP_ResumeCallHandlingArg.h"
#import "UMGSMMAP_ResumeCallHandlingRes.h"
#import "UMGSMMAP_RoamingNotAllowedCause.h"
#import "UMGSMMAP_RoamingNotAllowedParam.h"
#import "UMGSMMAP_RouteingNumber.h"
#import "UMGSMMAP_RoutingInfo.h"
#import "UMGSMMAP_RoutingInfoForLCSArg.h"
#import "UMGSMMAP_RoutingInfoForLCSRes.h"
#import "UMGSMMAP_RoutingInfoForLCS_Arg.h"
#import "UMGSMMAP_RoutingInfoForLCS_Res.h"
#import "UMGSMMAP_RoutingInfoForSM_Arg.h"
#import "UMGSMMAP_RoutingInfoForSM_Res.h"
#import "UMGSMMAP_SGSN_Capability.h"
#import "UMGSMMAP_SIWFSSignallingModifyArg.h"
#import "UMGSMMAP_SIWFSSignallingModifyRes.h"
#import "UMGSMMAP_SM_DeliveryOutcome.h"
#import "UMGSMMAP_SM_EnumeratedDeliveryFailureCause.h"
#import "UMGSMMAP_SM_RP_DA.h"
#import "UMGSMMAP_SM_RP_OA.h"
#import "UMGSMMAP_SRES.h"
#import "UMGSMMAP_SS_CSI.h"
#import "UMGSMMAP_SS_CamelData.h"
#import "UMGSMMAP_SS_Code.h"
#import "UMGSMMAP_SS_Data.h"
#import "UMGSMMAP_SS_EventList.h"
#import "UMGSMMAP_SS_EventSpecification.h"
#import "UMGSMMAP_SS_List.h"
#import "UMGSMMAP_SS_Status.h"
#import "UMGSMMAP_SS_SubscriptionOption.h"
#import "UMGSMMAP_SendAuthenticationInfoArg.h"
#import "UMGSMMAP_SendAuthenticationInfoRes.h"
#import "UMGSMMAP_SendGroupCallEndSignalArg.h"
#import "UMGSMMAP_SendGroupCallEndSignalRes.h"
#import "UMGSMMAP_SendIdentificationArg.h"
#import "UMGSMMAP_SendIdentificationRes.h"
#import "UMGSMMAP_SendRoutingInfoArg.h"
#import "UMGSMMAP_SendRoutingInfoForGprsArg.h"
#import "UMGSMMAP_SendRoutingInfoForGprsRes.h"
#import "UMGSMMAP_SendRoutingInfoRes.h"
#import "UMGSMMAP_ServiceIndicator.h"
#import "UMGSMMAP_ServiceKey.h"
#import "UMGSMMAP_SetReportingStateArg.h"
#import "UMGSMMAP_SetReportingStateRes.h"
#import "UMGSMMAP_ShortTermDenialParam.h"
#import "UMGSMMAP_SignalInfo.h"
#import "UMGSMMAP_Sm_DeliveryFailureCause.h"
#import "UMGSMMAP_Ss_ForBS.h"
#import "UMGSMMAP_Ss_IncompatibilityCause.h"
#import "UMGSMMAP_Ss_Info.h"
#import "UMGSMMAP_Ss_InvocationNotificationArg.h"
#import "UMGSMMAP_Ss_InvocationNotificationRes.h"
#import "UMGSMMAP_StatusReportArg.h"
#import "UMGSMMAP_StatusReportRes.h"
#import "UMGSMMAP_SubBusyForMT_SMS_Param.h"
#import "UMGSMMAP_SubscriberData.h"
#import "UMGSMMAP_SubscriberIdentity.h"
#import "UMGSMMAP_SubscriberInfo.h"
#import "UMGSMMAP_SubscriberLocationReport_Arg.h"
#import "UMGSMMAP_SubscriberLocationReport_Res.h"
#import "UMGSMMAP_SubscriberState.h"
#import "UMGSMMAP_SubscriberStatus.h"
#import "UMGSMMAP_SupportedCCBS_Phase.h"
#import "UMGSMMAP_SupportedCamelPhases.h"
#import "UMGSMMAP_SupportedGADShapes.h"
#import "UMGSMMAP_SystemFailureParam.h"
#import "UMGSMMAP_TA_Id.h"
#import "UMGSMMAP_TBCD_STRING.h"
#import "UMGSMMAP_TEID.h"
#import "UMGSMMAP_T_BcsmCamelTDPData.h"
#import "UMGSMMAP_T_BcsmCamelTDPDataList.h"
#import "UMGSMMAP_T_BcsmTriggerDetectionPoint.h"
#import "UMGSMMAP_T_CSI.h"
#import "UMGSMMAP_TeleservNotProvParam.h"
#import "UMGSMMAP_TeleserviceCode.h"
#import "UMGSMMAP_TeleserviceList.h"
#import "UMGSMMAP_Tmsi.h"
#import "UMGSMMAP_TraceReference.h"
#import "UMGSMMAP_TraceType.h"
#import "UMGSMMAP_TracingBufferFullParam.h"
#import "UMGSMMAP_TransactionId.h"
#import "UMGSMMAP_UMTS_SecurityContextData.h"
#import "UMGSMMAP_USSD_DataCodingScheme.h"
#import "UMGSMMAP_USSD_String.h"
#import "UMGSMMAP_UUI.h"
#import "UMGSMMAP_UUIndicator.h"
#import "UMGSMMAP_UU_Data.h"
#import "UMGSMMAP_UnauthorizedLCSClient_Diagnostic.h"
#import "UMGSMMAP_UnauthorizedLCSClient_Param.h"
#import "UMGSMMAP_UnauthorizedRequestingNetwork_Param.h"
#import "UMGSMMAP_UnexpectedDataParam.h"
#import "UMGSMMAP_UnidentifiedSubParam.h"
#import "UMGSMMAP_UnknownOrUnreachableLCSClient_Param.h"
#import "UMGSMMAP_UnknownSubscriberDiagnostic.h"
#import "UMGSMMAP_UnknownSubscriberParam.h"
#import "UMGSMMAP_UpdateGprsLocationArg.h"
#import "UMGSMMAP_UpdateGprsLocationRes.h"
#import "UMGSMMAP_UpdateLocationArg.h"
#import "UMGSMMAP_UpdateLocationRes.h"
#import "UMGSMMAP_Used_RAT_Type.h"
#import "UMGSMMAP_UserCSGInformation.h"
#import "UMGSMMAP_Ussd_Arg.h"
#import "UMGSMMAP_Ussd_Res.h"
#import "UMGSMMAP_VBSDataList.h"
#import "UMGSMMAP_VGCSDataList.h"
#import "UMGSMMAP_VLR_Capability.h"
#import "UMGSMMAP_Vertical_Accuracy.h"
#import "UMGSMMAP_VlrCamelSubscriptionInfo.h"
#import "UMGSMMAP_VoiceBroadcastData.h"
#import "UMGSMMAP_VoiceGroupCallData.h"
#import "UMGSMMAP_XRES.h"
#import "UMGSMMAP_ZoneCode.h"
#import "UMGSMMAP_ZoneCodeList.h"
#import "UMGSMMAP_asn1.h"
#import "UMGSMMAP_asn1_protocol.h"
#import "UMGSMMAP_gprsSupportIndicator.h"
#import "UMGSMMAP_SM_RP_MTI.h"
#import "UMGSMMAP_SM_RP_SMEA.h"
#import "UMGSMMAP_MAP_DialoguePDU.h"

#import "UMGSMMAP_IST_SupportIndicator.h"
#import "UMGSMMAP_CallDiversionTreatmentIndicator.h"
#import "UMGSMMAP_SuppressMTSS.h"
#import "UMGSMMAP_AnyTimeSubscriptionInterrogationArg.h"
#import "UMGSMMAP_AnyTimeSubscriptionInterrogationRes.h"

#import "UMGSMMAP_CheckIMEIArg.h"
#import "UMGSMMAP_CheckIMEIRes.h"

#import "UMGSMMAP_UESBI_Iu.h"
#import "UMGSMMAP_UESBI_IuA.h"
#import "UMGSMMAP_UESBI_IuB.h"
#import "UMGSMMAP_RequestedEquipmentInfo.h"
#import "UMGSMMAP_SendParametersArg.h"
#import "UMGSMMAP_RequestParameterList.h"
#import "UMGSMMAP_RequestParameter.h"
#import "UMGSMMAP_SentParameterList.h"
#import "UMGSMMAP_SentParameter.h"
#import "UMGSMMAP_Ki.h"



